/* Queue.js - a function for creating an efficient queue in JavaScript
 *
 * The author of this program, Safalra (Stephen Morley), irrevocably releases
 * all rights to this program, with the intention of it becoming part of the
 * public domain. Because this program is released into the public domain, it
 * comes with no warranty either expressed or implied, to the extent permitted
 * by law.
 *
 * For more public domain JavaScript code by the same author, visit:
 *
 * http://www.safalra.com/web-design/javascript/
 */


/* Creates a new Queue. A Queue is a first-in-first-out (FIFO) data structure.
 * Functions of the Queue object allow elements to be enqueued and dequeued, the
 * first element to be obtained without dequeuing, and for the current size of
 * the Queue and empty/non-empty status to be obtained.
 */
function Queue(){

  // the list of elements, initialised to the empty array
  var queue = [];

  // the amount of space at the front of the queue, initialised to zero
  var queueSpace = 0;

  /* Returns the size of this Queue. The size of a Queue is equal to the number
   * of elements that have been enqueued minus the number of elements that have
   * been dequeued.
   */
  this.getSize = function(){

    // return the number of elements in the queue
    return queue.length - queueSpace;

  }

  /* Returns true if this Queue is empty, and false otherwise. A Queue is empty
   * if the number of elements that have been enqueued equals the number of
   * elements that have been dequeued.
   */
  this.isEmpty = function(){

    // return true if the queue is empty, and false otherwise
    return (queue.length == 0);

  }

  /* Enqueues the specified element in this Queue. The parameter is:
   *
   * element - the element to enqueue
   */
  this.enqueue = function(element){
    queue.push(element);
  }

  /* Dequeues an element from this Queue. The oldest element in this Queue is
   * removed and returned. If this Queue is empty then undefined is returned.
   */
  this.dequeue = function(){

    // initialise the element to return to be undefined
    var element = undefined;

    // check whether the queue is empty
    if (queue.length){

      // fetch the oldest element in the queue
      element = queue[queueSpace];

      // update the amount of space and check whether a shift should occur
      if (++queueSpace * 2 >= queue.length){

        // set the queue equal to the non-empty portion of the queue
        queue = queue.slice(queueSpace);

        // reset the amount of space at the front of the queue
        queueSpace=0;

      }

    }

    // return the removed element
    return element;

  }

  /* Returns the oldest element in this Queue. If this Queue is empty then
   * undefined is returned. This function returns the same value as the dequeue
   * function, but does not remove the returned element from this Queue.
   */
  this.getOldestElement = function(){

    // initialise the element to return to be undefined
    var element = undefined;

    // if the queue is not element then fetch the oldest element in the queue
    if (queue.length) element = queue[queueSpace];

    // return the oldest element
    return element;

  }

}

//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------


var eEnabled = 1; // enable trigger 
var eOmitFromLog = 2; // omit from log file 
var eOmitFromOutput = 4; // omit trigger from output 
var eKeepEvaluating = 8; // keep evaluating 
var eIgnoreCase = 16; // ignore case when matching 
var eTriggerRegularExpression = 32; // trigger uses regular expression 
var eExpandVariables = 512; // expand variables like @direction 
var eReplace = 1024; // replace existing trigger of same name 
var eTemporary = 16384; // temporary - do not save to world file 

var varFYLocAreaMap="";
var varFYNpcLocMap="";
var varFYNpcAreaMap="";
var varFYNpcIDMap="";

var varTZAreaJumpMap="fy,flyShiyi,fyw,flyShiyi,qs,flyShiyi,cx,flyNangong,dm,flyNangong,wm,flyWM,gw,flyYing";

var varPathFY2FYW="west;west;west;west;west;west;west";
var varPathFY2QS="west;west;west;west;west;west;west;west;west;west;west;west";
var varPathFYW2QS="west;west;west;west;west";
var varPathCX2DM="north;northwest;northeast;northwest;northwest;northeast;northdown;northeast;north;north;north;north;north;north;north;north";
var varPathShiyi2FY="west;north;north;north;north;north";
var varPathNangong2CX="east";

var varPathJumpFY=varPathShiyi2FY;
var varPathJumpFYW=varPathJumpFY+";"+varPathFY2FYW;
var varPathJumpQS=varPathJumpFYW+";"+varPathFY2QS;
var varPathJumpCX=varPathNangong2CX;
var varPathJumpDM=varPathJumpCX+";"+varPathCX2DM;
var varPathJumpWM="";
var varPathJumpGW="";

var varStepMoveFlag=0;

var varMyQueue=new Queue();
var varMyQueue1=new Queue();
var varMyQueue2=new Queue();
var varMyQueue3=new Queue();
var varMyQueue4=new Queue();
var varMyQueue5=new Queue();

function initQueue(){
	varMyQueue=null;
	varMyQueue1=null;
	varMyQueue2=null;
	varMyQueue3=null;
	varMyQueue4=null;
	varMyQueue5=null;
	varMyQueue=new Queue();
	varMyQueue1=new Queue();
	varMyQueue2=new Queue();
	varMyQueue3=new Queue();
	varMyQueue4=new Queue();
	varMyQueue5=new Queue();
}

function checkLoopPattern(dir){
	var newdir=world.Replace(dir," �� ",",d,",true);
	var newdir=world.Replace(newdir,"��",",d,",true);
	var newdir=world.Replace(newdir,"��",",d",true);
	if (!world.arrayExists("sortpattern")) world.ArrayCreate("sortpattern");
	world.ArrayClear("sortpattern");
	world.ArrayImport("sortpattern",newdir,",");
	var dirarray1=world.ArrayExportKeys("sortpattern",",");
	var dirarray2=world.ArrayExportKeys("looppattern",",");
	if (dirarray1==dirarray2) return (true);
	else return (false);
}

var varLoopMapKeys;

function initLoopMapKeys(){
	varLoopMapKeys=null;
	varLoopMapKeys=new Array();
}

function addLoopMoveKey(k){
	varLoopMapKeys.push(k);	
}

function getLoopMove(dir){
	var l=varLoopMapKeys.length;
	var i=0;
	for (i=0;i<l;i++){
		var d=varLoopMapKeys[i];
		if (compareDir(dir,d)){
			return world.arrayGet("loopmoves",d);
		}	
	}
	return null;		
}

function compareDir(dir1,dir2){
//	world.note("compare "+dir1 +" with "+dir2);
	var newdir=world.Replace(dir1," �� ",",",true);
	var newdir=world.Replace(newdir,"��",",",true);
	var d1=newdir.split(",");
	var d2=dir2.split(",");
//	world.note("check "+d1 +" with "+d2);
	d1=d1.sort();
	d2=d2.sort();
	if (d1.toString()==d2.toString())
		return true;
	else
		return false;
}

function checkLoopEndPattern(dir){
	var newdir=world.Replace(dir," �� ",",d,",true);
	var newdir=world.Replace(newdir,"��",",d,",true);
	var newdir=world.Replace(newdir,"��",",d",true);
	if (!world.arrayExists("sortpattern")) world.ArrayCreate("sortpattern");
	world.ArrayClear("sortpattern");
	world.ArrayImport("sortpattern",newdir,",");
	var dirarray1=world.ArrayExportKeys("sortpattern",",");
	var dirarray2=world.ArrayExportKeys("loopendpattern",",");
	if (dirarray1==dirarray2) return (true);
	else return (false);
}
	
function addLoopEndPattern(pattern){
	world.ArraySet("loopendpattern",pattern,pattern);
}

function addLoopPattern(pattern){
	world.ArraySet("looppattern",pattern,pattern);
}

function initPatternArray(){
	if (!world.arrayExists("looppattern")) world.ArrayCreate("looppattern");
	if (!world.arrayExists("loopendpattern")) world.ArrayCreate("loopendpattern");
	world.ArrayClear("looppattern");
	world.ArrayClear("loopendpattern");
}


function disconnectWorld(){
	world.note("-->DISCONNECT");
	world.execute("NOCONNECT");
	world.save("");
	world.Disconnect();
}

function onEvent(event){
}



function onReconnect(){
}


function getColorCode(rgb){
	if (rgb==world.NormalColour(1))	return "$BLK$";
	if (rgb==world.NormalColour(2))	return "$RED$";
	if (rgb==world.NormalColour(3))	return "$GRN$";
	if (rgb==world.NormalColour(4))	return "$YEL$";
	if (rgb==world.NormalColour(5))	return "$BLU$";
	if (rgb==world.NormalColour(6))	return "$MAG$";
	if (rgb==world.NormalColour(7))	return "$CYN$";
	if (rgb==world.NormalColour(8))	return "$WHT$";
	if (rgb==world.BoldColour(1))	return "$NOR$";
	if (rgb==world.BoldColour(2))	return "$HIR$";
	if (rgb==world.BoldColour(3))	return "$HIG$";
	if (rgb==world.BoldColour(4))	return "$HIY$";
	if (rgb==world.BoldColour(5))	return "$HIB$";
	if (rgb==world.BoldColour(6))	return "$HIM$";
	if (rgb==world.BoldColour(7))	return "$HIC$";
	if (rgb==world.BoldColour(8))	return "$HIW$";
	return "$NOR$";
}



function getReversePath(oldpath){
//	world.note("---> getReversePath:"+oldpath);
	if (oldpath=="" || oldpath==null) return "";
	var p=oldpath;
	if (!world.arrayExists("mapReverseDir")){
		world.arrayCreate("mapReverseDir");
		world.arraySet("mapReverseDir","south","north");
		world.arraySet("mapReverseDir","north","south");
		world.arraySet("mapReverseDir","east","west");
		world.arraySet("mapReverseDir","west","east");
		world.arraySet("mapReverseDir","up","down");
		world.arraySet("mapReverseDir","down","up");
	
		world.arraySet("mapReverseDir","westup","eastdown");
		world.arraySet("mapReverseDir","westdown","eastup");
		world.arraySet("mapReverseDir","eastup","westdown");
		world.arraySet("mapReverseDir","eastdown","westup");
	
		world.arraySet("mapReverseDir","northup","southdown");
		world.arraySet("mapReverseDir","northdown","southup");
		world.arraySet("mapReverseDir","southup","northdown");
		world.arraySet("mapReverseDir","southdown","northup");
	
		world.arraySet("mapReverseDir","southeast","northwest");
		world.arraySet("mapReverseDir","northeast","southwest");
		world.arraySet("mapReverseDir","southwest","northeast");
		world.arraySet("mapReverseDir","northwest","southeast");
	}
	
	var t1=p.split(";");
	var t2=t1.pop();
	var t3=new Array();
	while(t2!=null){
		if (t2!="whisper"){
			var r=world.arrayGet("mapReverseDir",t2);
			if (r!=null && r!="" )
				t3.push(r);
		}
		t2=t1.pop();
	}
	var ret=t3.join(";");
	t1=null
	t2=null;
	t3=null;
	if (ret=="") ret=null;
//	world.note("---> generated reverse path:"+ret);
	return ret;	
}

function mergePath(backpath,nextpath){
//	world.note("---> enter mergePath:"+backpath+","+nextpath);
	if (backpath=="" || backpath==null) return nextpath;
	if (nextpath=="" || nextpath==null) return backpath;
	
	var p1=backpath.split(";");
	var p2=nextpath.split(";");
	var l=p1.length;
	if (l>p2.length) l=p2.length;
	if (l<0) l=0;
	var i=0;
	var t1,t2;
	for (i=0;i<l;i++){
		t1=p1.pop();
		t2=p2.shift();
		if (t1!=getReversePath(t2))	break;
	}
	
	var r=new Array();
	var n1=p1.shift();
	while(n1!=null){
		r.push(n1);
		n1=p1.shift();
	}	
	r.push(t1);
	r.push(t2);
	var n2=p2.shift();
	while(n2!=null){
		r.push(n2);
		n2=p2.shift();
	}
	var retpath=r.join(";");
//	world.note("---> generated mergePath:"+retpath);
	return retpath;
}

function generateMovesArray(allpath){
//	world.note("---> enter generateMovesArray:"+allpath);
	var pathArray=allpath.split(";");
	var i=0;
	var ret=new Array();
	var p;
	while(pathArray.length>0){
		var m="";
		var l=7;
		var i=0;
		if (l>pathArray.length) l=pathArray.length;
		for (i=0;i<l;i++){
			p=pathArray.shift();
			m=m+p+";";
		}
		m=m+"whisper";
		ret.push(m);
	}
//	world.note("---> generated generateMovesArray:"+ret);
	return ret;
}


function startMove(dirflag){
	if (!dirflag)
		world.execute("noDir");
	else
		world.execute("yesDir");
	world.execute("whisper");
}

var listSteps=new Array();
function initStep(){
	listSteps.length=0;
	listSteps=null;
	listSteps=new Array();
}
function addStep(step){
	listSteps.push(step);
	listSteps.push("tnext");
}

var listMoves=new Array();
var varLastMove="";
var listResumeMoves=new Array();


function initTJMove(){
	listMoves=null;
	listMoves=new Array();
	varLastMove=null;
	varStepMoveFlag=0;
}
function addMove(move){
	if (varStepMoveFlag==1){
		addStepMove(move);
		return;	
	}
	var a=move.split(";");
	var i=1;
	var t="";
	while(a.length>0){
		var m=a.shift();
		if (m=="break" ){
			if (t!=null){
				if (t.indexOf("-")==-1)	t=t+";whisper";
				listMoves.push(t+"");
				i=1;
				t="";
			}
			continue;
		}
		var r=getReversePath(m);
		if (r==null ){
			if (t!=null){
				if (t.indexOf("-")==-1)	t=t+";whisper";
//				t=t+";whisper";
				listMoves.push(t+"");
				i=1;
				t=m;
			}
			continue;
		}
		if (t=="") t=m;
		else t=t+";"+m;
		i++;
		if (i>8){
				t=t+";whisper";
				listMoves.push(t);
				i=1;
				t="";
		}
	}
	if (t!=""){
		t=t+";whisper";
		listMoves.push(t);
		i=1;
		t="";
	}	
}

function addMove2(move){
	if (varStepMoveFlag==1){
		addStepMove2(move);
		return;	
	}
	listMoves.push(move+"");
}

function addTJMove2(move){
	listMoves.push(move+"");
}

function addTJMove(move){
	var a=move.split(";");
	var i=1;
	var t="";
	while(a.length>0){
		var m=a.shift();
		if (m=="break" ){
			if (t!=null){
				if (t.indexOf("-")==-1)	t=t+";whisper";
				listMoves.push(t+"");
				i=1;
				t="";
			}
			continue;
		}
		var r=getReversePath(m);
		if (r==null ){
			if (t!=null){
				if (t.indexOf("-")==-1)	t=t+";whisper";
//				t=t+";whisper";
				listMoves.push(t+"");
				i=1;
				t=m;
			}
			continue;
		}
		if (t=="") t=m;
		else t=t+";"+m;
		i++;
		if (i>8){
				t=t+";whisper";
				listMoves.push(t);
				i=1;
				t="";
		}
	}
	if (t!=""){
		t=t+";whisper";
		listMoves.push(t);
		i=1;
		t="";
	}	
}

function getNextTJMove(){
	varLastMove=listMoves.shift();
	return varLastMove;
}

function backTJLastMove(){
	listMoves=null;
	listMoves=new Array();
	var m=getReversePath(varLastMove);
	if (m==null) m="";
	var backs=m.split(";");
	listMoves.push("doTJKill");
	while (backs.length>0){
		var b=backs.shift();
		listMoves.push(b+";doTJKill");	
	}
	
	listMoves.push("stopTJKill");
	world.execute("addCancelTJ");
}

function getMapKey(entry){
	var i=entry.indexOf(":");
	if (i>0){
		return entry.substr(0,i);
	}else{
		return entry;
	}
}

function getMapValue(entry){
	var i=entry.indexOf(":");
	if (i>0){
		return entry.substr(i+1,entry.length-i-1);
	}else{
		return entry;
	}
}

function initFYMaps(){
	if (world.ArrayExists("FYLocAreaMap"))
		world.arrayClear("FYLocAreaMap");
	else
		world.ArrayCreate("FYLocAreaMap");

	if (world.ArrayExists("FYNpcAreaMap"))
		world.arrayClear("FYNpcAreaMap");
	else
		world.ArrayCreate("FYNpcAreaMap");

	if (world.ArrayExists("FYNpcLocMap"))
		world.arrayClear("FYNpcLocMap");
	else
		world.ArrayCreate("FYNpcLocMap");
		
	if (world.ArrayExists("FYNpcIDMap"))
		world.arrayClear("FYNpcIDMap");
	else
		world.ArrayCreate("FYNpcIDMap");
		
	var list1=varFYLocAreaMap.split(";");		
	while (list1.length>0){
		var l=list1.shift();
		world.ArraySet("FYLocAreaMap",getMapKey(l),getMapValue(l));
	}

	list1=varFYNpcAreaMap.split(";");		
	while (list1.length>0){
		var l=list1.shift();
		world.ArraySet("FYNpcAreaMap",getMapKey(l),getMapValue(l));
	}

	list1=varFYNpcLocMap.split(";");		
	while (list1.length>0){
		var l=list1.shift();
		world.ArraySet("FYNpcLocMap",getMapKey(l),getMapValue(l));
	}
	list1=varFYNpcIDMap.split(";");		
	while (list1.length>0){
		var l=list1.shift();
		world.ArraySet("FYNpcIDMap",getMapKey(l),getMapValue(l));
	}
	world.note("script: init fy maps done");					
}


function generateTQMovesByLoc(loc){
	var area=world.arrayGet("FYLocAreaMap",loc);
	if (area==null || area==""){
		world.execute("addTQLog missing-location:"+loc);
		world.execute("quest");
		return;	
	}
	var areas=area.split(",");
	areas.reverse();
	initMove();
	world.execute("addStartTQ");
	var firstArea=false;
	while(areas.length>0){
		var a=areas.shift();
		if (firstArea){
			addMove2("flyShiyi");
			addMove2("shiyi-fy");
		}
		world.execute("addMap"+a);
		firstArea=true;
	}
	world.execute("addFailTQ");
}

function startTQMove(){
	world.execute("whisper");
}

function pauseMove(){
	listResumeMoves=null;
	listResumeMoves=listMoves.join(":").split(":");
	if (listResumeMoves==null) 
		listResumeMoves=new Array();
//	listResumeMoves.unshift(varLastMove);
}


function resumeMove(){
	listMoves=null;
	listMoves=listResumeMoves.join(":").split(":");
	world.exeute("whisper");
}

function generateSearchMoves(searchaction,resumeaction){
	listMoves=null;
	listMoves=new Array();
	var m=getReversePath(varLastMove);
	if (m==null) m="";
	var backs=m.split(";");
	listMoves.push(searchaction);
	while (backs.length>0){
		var b=backs.shift();
		if (b==null || b=="") b=""+searchaction
		else b=b+";"+searchaction;
		listMoves.push(b);	
	}
	listMoves.push(varLastMove);
	listMoves.push(resumeaction);
	listMoves=listMoves.concat(listResumeMoves);
	
}

function getNextMove(){
	varLastMove=listMoves.shift();
	return varLastMove;
}

function getNextStep(){
	return listSteps.shift();
}

function getNpcIDs(npc){
	var nid=world.arrayGet("FYNpcIDMap",npc);
	if (nid==null || nid=="") return "";
	else return nid.split(",").shift();
}	
function getNpcLoc(npc){
	var loc=world.arrayGet("FYNpcLocMap",npc);
	if (loc==null || loc=="") return "";
	return loc.split(",").shift();
}	
function skipMove(){
	listMoves.shift();
}

function generateTQMovesByNpc(npc){
	var areas=world.arrayGet("FYNpcAreaMap",npc);
	if (areas==null || areas==""){
		world.execute("addTQLog missing-location:"+loc);
		world.execute("quest");
		return;	
	}
	var nid=getNpcIDs(npc);
	var area=areas.split(",").shift();
	initMove();
	world.execute("addStartTQ");
	addMove2("south;goo3 "+nid);
	addMove2("flyShiyi");
	addMove2("shiyi-fy");
	world.execute("addMap"+area);
	world.execute("addFailTQ");
}

function initStepMove(){
	listMoves=null;
	listMoves=new Array();
	varLastMove=null;
	varStepMoveFlag=1;
}

function addStepMove(move){
//	world.note("addStepMove:"+move);
	var a=move.split(";");
	var i=1;
	var smove="";
	while(a.length>0){
		var m=a.shift();
		if (m=="break" ){
			//skip it
			continue;
		}
		var r=getReversePath(m);
		if (r==null ){
			if (m.indexOf("-")>0){
				listMoves.push(m);
				listMoves.push("tasklocate");
			}else{
				if (smove!="") {
					listMoves.push(smove+";whisper");
					listMoves.push("tasklocate");
				}
				smove=m+";";
			}
		}else{
			if (smove!=""){
				listMoves.push(smove+m+";whisper");
				listMoves.push("tasklocate");
				smove="";				
			}else{
				listMoves.push(m+";whisper");
				listMoves.push("tasklocate");
			}	
			
		}
	}
		
}

function addStepMove2(move){
//	world.note("addStepMove2:"+move);
	listMoves.push(move+"");
//	listMoves.push("whisper");
//	listMoves.push("tasklocate");
}

function stopStepMove(){
	varStepMoveFlag=0;
}

function checkPileWinnable(){
var piles=new Array(6);
piles[0]=world.getVariable("varPile1");
piles[1]=world.getVariable("varPile2");
piles[2]=world.getVariable("varPile3");
piles[3]=world.getVariable("varPile4");
piles[4]=world.getVariable("varPile5");
piles[5]=world.getVariable("varPile6");
var sum, i;
for(i=0,sum=0;i<piles.length;i++)
  sum^=piles[i];
world.note("--->check pile value:"+sum);
if(sum!=0) return true;
else return false;
}

function takePile(){
var piles=new Array(6);
piles[0]=world.getVariable("varPile1");
piles[1]=world.getVariable("varPile2");
piles[2]=world.getVariable("varPile3");
piles[3]=world.getVariable("varPile4");
piles[4]=world.getVariable("varPile5");
piles[5]=world.getVariable("varPile6");
var sum, i;
for(i=0,sum=0;i<piles.length;i++)
  sum^=piles[i];
world.note("--->pre sum value:"+sum);
if(sum==0){
  for(i=0;i<piles.length;i++)
    sum|=piles[i];
  if((sum & 8)>0) sum=15;
  else if((sum & 4)>0) sum=7;
  else if((sum & 2)>0) sum=3;
  else {
    world.note("---> lose sum:"+sum);
    world.setVariable("varPilePosition",0);
    world.setVariable("varPileAmount",0);
    return "fail"
  }
}
world.note("--->sum value:"+sum);
var best=100, besti=-1;
var mbest=100, mbesti=-1;
for(i=piles.length-1;i>=0;i--){
  var s=(piles[i]^sum);
  if(piles[i] > s && (s==3||s==4||s==7||s==8||s==11||s==12||s==15))
  {
    mbest=piles[i]-s;
    mbesti=i+1;
    break;
  }
}
for(i=piles.length-1;i>=0;i--){
  if(piles[i] > (piles[i]^sum) && (best > piles[i]-(piles[i]^sum)))
  {
    best=piles[i]-(piles[i]^sum);
    besti=i+1;
  }
}
if (mbesti!=-1){
    world.note("---> good action:"+ mbesti+" "+mbest);
    world.setVariable("varPilePosition",mbesti);
    world.setVariable("varPileAmount",mbest);
	return "good";  	  
}else if(besti!=-1){
    world.note("---> normal action:"+ besti+" "+best);
    world.setVariable("varPilePosition",besti);
    world.setVariable("varPileAmount",best);
	return "normal";  	  
//  world.execute("take "+besti+" "+best);
}else{
    world.note("---> no best");
    world.setVariable("varPilePosition",0);
    world.setVariable("varPileAmount",0);
    return "fail";
}
}

//task robot
var taskavailablelist=[];//new Array();
var tasknearbylist=[];//new Array();
var taskfoundlist=[];//new Array();
var tasklocatedlist=[];//new Array();

function initTaskList(){
	taskavailablelist=[];//new Array();
	tasknearbylist=[];//new Array();
	taskfoundlist=[];//new Array();
	tasklocatedlist=[];//new Array();
}
var backupListMoves=[];
function backupMoves(){
  backupListMoves=listMoves.join(",").split(",");
  listMoves=null;	
  listMoves=new Array();	
}
function restoreMoves(){
  listMoves=backupListMoves.join(",").split(",");
  backupListMoves=null;	
  backupListMoves=new Array();	
}

function initMove(){
	listMoves.length=0;
	listMoves=null;
	listMoves=new Array();
	varLastMove=null;
	listResumeMoves=null;
    backupListMoves=null;
	listResumeMoves=new Array();
    backupListMoves=new Array();
}

function cls(){
//	world.deleteOutput();
}


function chineseToNum(cn){
    var arab, parts, cnChars = '��һ�����������߰˾�'
 
    if (!cn) {
        return 0
    }
 
    if (cn.indexOf('��') !== -1){
        parts = cn.split('��')
        return cnNum2ArabNum(parts[0]) * 1e8 + cnNum2ArabNum(parts[1])
    }
 
    if (cn.indexOf('��') !== -1){
        parts = cn.split('��')
        return cnNum2ArabNum(parts[0]) * 1e4 + cnNum2ArabNum(parts[1])
    }
 
    if (cn.indexOf('ʮ') === 0){
        cn = 'һ' + cn
    }
 
    arab = cn
        .replace(/[��һ�����������߰˾�]/g, function (a) {
            return '+' + cnChars.indexOf(a)
        })
        .replace(/(ʮ|��|ǧ)/g, function(a, b){
            return '*' + (
                b == 'ʮ' ? 1e1 :
                b == '��' ? 1e2 : 1e3
            )
        })
//    return arab;
    return (new Function('return ' + arab))()
}


//function



//end of script file