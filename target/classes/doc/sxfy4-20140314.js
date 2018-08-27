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

var varMyList1=new Array();
var varMyList2=new Array();
var varMyList3=new Array();
var varMyList4=new Array();
var varMyList5=new Array();

function initList(){
	varMyList1=new Array();
	varMyList2=new Array();
	varMyList3=new Array();
	varMyList4=new Array();
	varMyList5=new Array();
}

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
	var newdir=world.Replace(dir," 和 ",",d,",true);
	var newdir=world.Replace(newdir,"、",",d,",true);
	var newdir=world.Replace(newdir,"。",",d",true);
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
	var newdir=world.Replace(dir1," 和 ",",",true);
	var newdir=world.Replace(newdir,"、",",",true);
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
	var newdir=world.Replace(dir," 和 ",",d,",true);
	var newdir=world.Replace(newdir,"、",",d,",true);
	var newdir=world.Replace(newdir,"。",",d",true);
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
    var arab, parts, cnChars = '零一二三四五六七八九'
 
    if (!cn) {
        return 0
    }
 
    if (cn.indexOf('亿') !== -1){
        parts = cn.split('亿')
        return cnNum2ArabNum(parts[0]) * 1e8 + cnNum2ArabNum(parts[1])
    }
 
    if (cn.indexOf('万') !== -1){
        parts = cn.split('万')
        return cnNum2ArabNum(parts[0]) * 1e4 + cnNum2ArabNum(parts[1])
    }
 
    if (cn.indexOf('十') === 0){
        cn = '一' + cn
    }
 
    arab = cn
        .replace(/[零一二三四五六七八九]/g, function (a) {
            return '+' + cnChars.indexOf(a)
        })
        .replace(/(十|百|千)/g, function(a, b){
            return '*' + (
                b == '十' ? 1e1 :
                b == '百' ? 1e2 : 1e3
            )
        })
//    return arab;
    return (new Function('return ' + arab))()
}


//function

//auto quest script

var mapQuestNpcKill={};
var mapQuestItemKill={};
var mapQuestItemKillAdditional={};
var mapQuestItemGet={};
var	mapNpcName={};
var	mapItemName={};
var	mapQuestQueue={};
var	mapQuestNpcGhost={};

var listQuestGone=new Array();
var listQuestActiveQueue=new Array();

function initQuestAction(){
	mapQuestNpcKill={};
	mapQuestItemKill={};
	mapQuestItemKillAdditional={};
	mapQuestItemGet={};
	mapNpcName={};
	mapItemName={};
	mapQuestQueue={};
	mapQuestNpcGhost={};
	listQuestGone=new Array();
	listQuestActiveQueue=new Array();

	
	loadQuestNpcKillMap();
	loadQuestItemKillMap();
	loadQuestItemGetMap();
	loadQuestItemKillAdditionalMap();
	loadQuestNpcNameMap();
	loadQuestItemNameMap();
	loadQuestNpcGhostMap();
	
}

function initQuestReturn(){
	mapItemName={};
	mapQuestQueue={};
	listQuestActiveQueue=new Array();

	loadQuestItemNameMap();
}

function generateActiveQuestQueue(){
	//remove already gone quest
	for (var q in mapQuestQueue){
		if (arrayContains(listQuestGone,q))
			delete mapQuestQueue[q];
	}	
	
	var listT1=new Array();	
	for (var q in mapQuestQueue){
		listT1.push(q+","+mapQuestQueue[q]);
	}	
	listT1.sort(CompareForSort);
	listQuestActiveQueue=new Array();
	for (var i=0;i<listT1.length;i++){
		listQuestActiveQueue.push((listT1[i].split(","))[0]);	
	}
}


function generateQuestActionMove(qpath){
	var moves=qpath.split(";");
	var move="";		
	for (var i=0;i<moves.length;i++){
		if (moves[i].indexOf("goo")==0 ){
			addMove2(moves[i]);
			move="";
//		}else if (moves[i].indexOf("aasee")==0){
//			addMove2(moves[i]+";whisper");
//			move="";
		}else if (moves[i].indexOf("-")>0 ||  moves[i].indexOf("checkBusy")>=0 || moves[i].indexOf("umk")>=0 || moves[i].indexOf("smk")>=0 
			|| moves[i].indexOf("waitSec")>=0 ){
			if (move!=""){
				addMove2(move+";whisper");
				addMove2(moves[i]);
				move="";
			}else{
				addMove2(moves[i]);
			}
		}else if ( moves[i].indexOf("#")>=0){
			if (move!=""){
				addMove2(move+";whisper");
				addMove2(moves[i]+";whisper");
				move="";
			}else{
				addMove2(moves[i]+";whisper");
			}
		}else if (moves[i].indexOf("auto")>=0){
			if (move!=""){
				addMove2(move+";"+moves[i]);
				move="";
			}else{
				addMove2(moves[i]);
			}
		}else{
			if (move==""){
				move=moves[i];
			}else{
				move=move+";"+moves[i];
			}
		}
	}	
	if (move!="")
		addMove2(move+";whisper");
	
}

function generateQuestPostMove(){
	addMove2("goo illusionist nan");	
//	addMove2("checkBusy");	
	addMove2("down;enter;questDoneOrGone;questReturnAfterDone");
	addMove2("askQuestReturn");
	addMove2("out;south;checkPoison");	
	addMove2("checkStatus");	
	addMove2("checkQuestItem");
	addMove2("west;openBox");	
	addMove2("east;north;enter;questList");
	addMove2("goNextQuest");
}

function generateQuestClearShaolinMove(){
	addMove2("goo illusionist nan");	
//	addMove2("checkBusy");	
	addMove2("down;enter;questDoneOrGone;questReturnAfterDone");
	addMove2("askQuestReturn");
	addMove2("out;south;checkPoison");	
	addMove2("checkStatus");	
	addMove2("checkQuestItem");
	addMove2("south;east;north;whisper");
	addMove2("goot nangong");
//	addMove2("checkBusy");	
	addMove2("east;cx-huang");
	addMove2("sw;w;wd;sw;give 1 cash to shaolin monk;whisper");
	addMove2("goo illusionist nan");	
//	addMove2("checkBusy");	
	addMove2("questList");
	addMove2("goNextQuest");
}

function queryQuestPath(cname){
	var ret=queryQuestKillPath(cname);
	if (ret==null)
		ret=queryQuestItemPath(cname);
	if (ret==null){
		logQuest("missing quest path for "+cname);
	}
	return ret;	
}

function logQuest(log){
	var l=world.getvariable("varQuestLog");
	if (l==null || l=="" || l== undefined)
		l=log;
	else
		l=l+"\r\n"+log;
	world.setvariable("varQuestLog",l);		
}

function queryQuestKillPath(cname){
	var ret=null;	
	var npcEname=queryQuestKillName(cname);
	ret=mapQuestNpcKill[cname];
	if (ret!=null && npcEname!=null){
		ret=ret.replace(/@/g,npcEname);
		ret=ret.replace(/;kill2 /g,";autokill ");
		ret=ret.replace(/;kill /g,";autoQuestKill ");
		ret=ret.replace(/;fight /g,";autoQuestFightKill ");
		ret=ret.replace(/;stealkill /g,";autoQuestStealKill ");
		ret=ret.replace(/;askkill /g,";autoQuestAskKill ");
	}
	world.note("---> quest kill path:"+ret);
	return ret;
}

function queryQuestItemPath(cname){
	var ret=null;	
	var itemEname;
	
	ret=mapQuestItemGet[cname];
	if (ret==null)
		ret=mapQuestItemKillAdditional[cname];	
	if (ret==null){
		var npcCname=mapQuestItemKill[cname];
		if (npcCname!=null){
			var npcEname=mapNpcName[npcCname];	
			ret=mapQuestNpcKill[npcCname];
			if (ret!=null && npcEname!=null){
				ret=ret.replace(/@/g,npcEname);
				ret=ret.replace(/;kill2 /g,";autokill ");
				ret=ret.replace(/;kill /g,";autoQuestKill ");
				ret=ret.replace(/;fight /g,";autoQuestFightKill ");
				ret=ret.replace(/;stealkill /g,";autoQuestStealKill ");
				ret=ret.replace(/;askkill /g,";autoQuestAskKill ");
			}
						
		}
	}else{
		ret=ret.replace(/;kill2 /g,";autokill ");
		ret=ret.replace(/;kill /g,";autoQuestKill ");
		ret=ret.replace(/;fight /g,";autoQuestFightKill ");
		ret=ret.replace(/;stealkill /g,";autoQuestStealKill ");
		ret=ret.replace(/;askkill /g,";autoQuestAskKill ");
	}
//	if (ret!=null){
//		var ename=queryQuestItemName;
//	}
	world.note("---> quest item kill path:"+ret);
	return ret;
}

function queryQuestType(cname){
	var ret=null;	
	ret=mapQuestNpcKill[cname];
	if (ret!=null)
		return "npckill";
		
	ret=mapQuestItemGet[cname];
	if (ret==null)
		return "itemkill";
	else
		return "itemget";
}

function queryQuestKillName(cname){
	var ret=null;	
	ret=mapNpcName[cname];	
	return ret;
}

function queryQuestItemName(cname){
	var ret=null;	
	ret=mapItemName[cname];	
	return ret;
}


function loadQuestNpcGhostMap(){
   var fso, f1, ts, s;
   var ForReading = 1;
   fso = new ActiveXObject("Scripting.FileSystemObject");
   ts = fso.OpenTextFile("C:\\Workspace\\FY3Map\\fy4\\questNpcGhost.txt", ForReading);
   s = ts.ReadLine();
   while (!ts.AtEndOfStream){
	   var listLine=s.split(",");
	   if (s.indexOf("//")==-1)
		   mapQuestNpcGhost[listLine[0]]=listLine[1];
	   s = ts.ReadLine();
   }
   ts.Close();
   world.note("---> loading mapQuestNpcGhost completed");
}

function loadQuestNpcKillMap(){
   var fso, f1, ts, s;
   var ForReading = 1;
   fso = new ActiveXObject("Scripting.FileSystemObject");
   ts = fso.OpenTextFile("C:\\Workspace\\FY3Map\\fy4\\questNpcKill.txt", ForReading);
   s = ts.ReadLine();
   while (!ts.AtEndOfStream){
	   var listLine=s.split(",");
	   if (s.indexOf("//")==-1)
		   mapQuestNpcKill[listLine[1]]=listLine[7];
	   s = ts.ReadLine();
   }
   ts.Close();
   world.note("---> loading mapQuestNpcKill completed");
}

function loadQuestItemKillMap(){
   var fso, f1, ts, s;
   var ForReading = 1;
   fso = new ActiveXObject("Scripting.FileSystemObject");
   ts = fso.OpenTextFile("C:\\Workspace\\FY3Map\\fy4\\questItemKill.txt", ForReading);
   s = ts.ReadLine();
   while (!ts.AtEndOfStream){
	   var listLine=s.split(",");
	   if (s.indexOf("//")==-1){
		   var npcName=cleanQuestNpcCname(listLine[5]);
		   mapQuestItemKill[listLine[1]]=npcName;
	   }
	   s = ts.ReadLine();
   }
   ts.Close();
   world.note("---> loading mapQuestItemKill completed");
}

function loadQuestItemGetMap(){
   var fso, f1, ts, s;
   var ForReading = 1;
   fso = new ActiveXObject("Scripting.FileSystemObject");
   ts = fso.OpenTextFile("C:\\Workspace\\FY3Map\\fy4\\questItemGet.txt", ForReading);
   s = ts.ReadLine();
   while (!ts.AtEndOfStream){
	   var listLine=s.split(",");
	   if (s.indexOf("//")==-1)
		   mapQuestItemGet[listLine[1]]=listLine[7];
	   s = ts.ReadLine();
   }
   ts.Close();
   world.note("---> loading mapQuestItemGet completed");
}

function loadQuestItemKillAdditionalMap(){
   var fso, f1, ts, s;
   var ForReading = 1;
   fso = new ActiveXObject("Scripting.FileSystemObject");
   ts = fso.OpenTextFile("C:\\Workspace\\FY3Map\\fy4\\questItemKillAddtional.txt", ForReading);
   s = ts.ReadLine();
   while (!ts.AtEndOfStream){
	   var listLine=s.split(",");
	   if (s.indexOf("//")==-1){
		   mapQuestItemKillAdditional[listLine[1]]=listLine[9];
	   }
	   s = ts.ReadLine();
   }
   ts.Close();
   world.note("---> loading mapQuestItemKillAdditional completed");
}

function loadQuestItemNameMap(){
   var fso, f1, ts, s;
   var ForReading = 1;
   fso = new ActiveXObject("Scripting.FileSystemObject");
   ts = fso.OpenTextFile("C:\\Workspace\\FY3Map\\fy4\\questItemGet.txt", ForReading);
   s = ts.ReadLine();
   while (!ts.AtEndOfStream){
	   var listLine=s.split(",");
	   if (s.indexOf("//")==-1){
		   mapItemName[listLine[1]]=listLine[2];
	   }
	   s = ts.ReadLine();
   }
   ts.Close();
   ts = fso.OpenTextFile("C:\\Workspace\\FY3Map\\fy4\\questItemKill.txt", ForReading);
   s = ts.ReadLine();
   while (!ts.AtEndOfStream){
	   var listLine=s.split(",");
	   if (s.indexOf("//")==-1){
		   mapItemName[listLine[1]]=listLine[2];
	   }
	   s = ts.ReadLine();
   }
   ts.Close();
   ts = fso.OpenTextFile("C:\\Workspace\\FY3Map\\fy4\\questItemKillAddtional.txt", ForReading);
   s = ts.ReadLine();
   while (!ts.AtEndOfStream){
	   var listLine=s.split(",");
	   if (s.indexOf("//")==-1){
		   mapItemName[listLine[1]]=listLine[2];
	   }
	   s = ts.ReadLine();
   }
   ts.Close();
   world.note("---> loading mapItemName completed");
}

function loadQuestNpcNameMap(){
   var fso, f1, ts, s;
   var ForReading = 1;
   fso = new ActiveXObject("Scripting.FileSystemObject");
   ts = fso.OpenTextFile("C:\\Workspace\\FY3Map\\fy4\\questNpcKill.txt", ForReading);
   s = ts.ReadLine();
   while (!ts.AtEndOfStream){
	   var listLine=s.split(",");
	   if (s.indexOf("//")==-1){
		   mapNpcName[listLine[1]]=listLine[2];
	   }
	   s = ts.ReadLine();
   }
   ts.Close();
   world.note("---> loading mapNpcName completed");
}

function isQuestNpcGhost(cName){
	var ename=mapNpcName[cName];
	if (ename==null || ename=="")
		return false;
	var gpath=mapQuestNpcGhost[ename];
	if (gpath==null||gpath=="")
		return false;
	else 
		return true;
}

function cleanQuestNpcCname(cname){
	var ret=cname.replace(/\"/g,"");
	ret=ret.replace(/NOR/g,"");	
	ret=ret.replace(/HIC/g,"");	
	ret=ret.replace(/HIY/g,"");	
	ret=ret.replace(/WHT/g,"");	
	ret=ret.replace(/HIR/g,"");	
	ret=ret.replace(/HIG/g,"");	
	ret=ret.replace(/HIW/g,"");	
	ret=ret.replace(/HIW/g,"");	
	ret=ret.replace(/HIW/g,"");	
	return ret;
	
}

function arrayContains(a, obj) {
    var i = a.length;
    while (i--) {
       if (a[i] === obj) {
           return true;
       }
    }
    return false;
}


function CompareForSort(param1, param2)
{
   var first = parseInt(param1.split(",")[1]);
   var second = parseInt(param2.split(",")[1]);
   
   if (first == second)
      return 0;
   if (first < second)
      return -1;
   else
      return 1; 
}

function endWithNumber(s){
	if (s==null || s.legth==0)
		return false;
	var c=s.substring(s.length-1);
	if (c=="1" || c=="2" || c=="3" || c=="4" || c=="5" || c=="6" || c=="7" || c=="8" || c=="9" || c=="0")
		return true;
	else
		return false;
	
}

var	mapMissionNpc={};

function loadMissionNpcMap(){
   var fso, f1, ts, s;
   var ForReading = 1;
   fso = new ActiveXObject("Scripting.FileSystemObject");
   ts = fso.OpenTextFile("C:\\mud\\fyvi\\missionNpcKill.txt", ForReading);
   s = ts.ReadLine();
   while (!ts.AtEndOfStream){
	   var listLine=s.split(",");
	   if (s.indexOf("//")==-1)
		   mapMissionNpc[listLine[0]]=listLine[1];
	   s = ts.ReadLine();
   }
   ts.Close();
   world.note("---> loading mapMissionNpc completed");
}

function queryMissionNpc(cname){
	return mapMissionNpc[cname];
}

function generateAutokillPerform(pfm){
	var t=world.getvariable("varKillTarget");
	var ret=""
	if (t==""){
		ret=pfm.replace(" @","");
		ret=ret.replace(" @","");
		ret=ret.replace(" on","");
	}else if (t=="abortkill"){
		world.note("---> abort autokill with back seal");
		ret="burn";
		world.setvariable("varKillTarget","");
	}else{
		ret=pfm.replace(" @"," "+t);
		ret=ret.replace(" @"," "+t);
	}
	return ret;
	
}


var mapItem={};

function initMapItem(){
	mapItem={};
	var items=world.getvariable("varCheckItem");
	if (items!=null && items !="" && items!=undefined){
		var itemList=items.split(",");
		var i=0;
		for (i=0;i<itemList.length;i++){
			mapItem[itemList[i]]="no";	
			world.note("---> init mapItem with key "+itemList[i]);		
		}
	}
}

function checkMapItemResult(){
	var ret=true;
	var items=world.getvariable("varCheckItem");
	if (items!=null && items !="" && items!=undefined){
		var itemList=items.split(",");
		var i=0;
		for (i=0;i<itemList.length;i++){
			if (mapItem[itemList[i]]=="no")
				ret=false;	
		}
	}
	return ret;		
}

var mapMazeCoin={};

// start of location path map

var mapPathMoveMapping={}
var mapLocationNameId={};
var mapLocationIdPath={};
var listLocationId=new Array();

var mapGhostNpc={};
var mapAreaName={};
var mapAreaLocName={};

function initAreaNameMap(){
	mapAreaName["baiyun"]="白云岛";
	mapAreaName["bat"]="蝙蝠岛";
	mapAreaName["bawang"]="霸王山庄";
	mapAreaName["biancheng"]="边城";
	mapAreaName["cave"]=""; //no area chinese name
	mapAreaName["chenxiang"]="沉香";
	mapAreaName["chuenyu"]="黑松林";
	mapAreaName["daimiao"]="岱庙";
	mapAreaName["death"]="地府";
	mapAreaName["eren"]="藏北";
	mapAreaName["fugui"]="富贵";
	mapAreaName["fy"]="风云城";
	mapAreaName["fywall"]="风云城墙";
	mapAreaName["fycycle"]="风云周边";
	mapAreaName["ghost"]="幽灵山庄";
	mapAreaName["guanwai"]=""; //关外
	mapAreaName["guanyin"]="大漠之北";
	mapAreaName["huangshan"]="黄山";
	mapAreaName["huashan"]="华山";
	mapAreaName["jinan"]="济南";
	mapAreaName["laowu"]="老屋";
	mapAreaName["libie"]="";
	mapAreaName["loulan"]="大漠附近";
	mapAreaName["manglin"]="莽林";
	mapAreaName["oldpine"]="老林";
	mapAreaName["palace"]="帝王谷";
	mapAreaName["qianfo"]="千佛";
	mapAreaName["qianjin"]="千金楼";
	mapAreaName["qingping"]="清平山庄";
	mapAreaName["quicksand"]="大漠沉沙";
	mapAreaName["resort"]="关外";
	mapAreaName["shanliu"]="";
	mapAreaName["shanxi"]="山西";
	mapAreaName["shaolin"]="少林";
	mapAreaName["sharen"]=""; //no area chinese name
	mapAreaName["shenshui"]="神水附近";
	mapAreaName["songshan"]="嵩山";
	mapAreaName["taoguan"]="三清宫";
	mapAreaName["taishan"]="泰山";
	mapAreaName["taiping"]="藏北";
	mapAreaName["tieflag"]="大旗门";
	mapAreaName["wanmei"]="万梅山庄,万梅";
	mapAreaName["wolfmount"]="狼山";
	mapAreaName["wudang"]="武当";
	mapAreaName["xinjiang"]="新疆";
	mapAreaName["yingou"]="银钩赌坊";
	mapAreaName["zangbei"]="藏北";
	mapAreaName["zhaoze"]="沉香之南";
	
}


function initLocationMaps(){
	mapAreaName={};
	mapAreaLocName={};
	initAreaNameMap();
	
	mapLocationNameId={};
	mapLocationIdPath={};
	listLocationId=new Array();
	
	mapPathMoveMapping["s"]="south";
	mapPathMoveMapping["w"]="west";
	mapPathMoveMapping["e"]="east";
	mapPathMoveMapping["n"]="north";
	mapPathMoveMapping["u"]="up";
	mapPathMoveMapping["d"]="down";
	mapPathMoveMapping["se"]="southeast";
	mapPathMoveMapping["ne"]="northeast";
	mapPathMoveMapping["sw"]="southwest";
	mapPathMoveMapping["nw"]="northwest";
	mapPathMoveMapping["su"]="southup";
	mapPathMoveMapping["sd"]="southdown";
	mapPathMoveMapping["nu"]="northup";
	mapPathMoveMapping["nd"]="northdown";
	mapPathMoveMapping["eu"]="eastup";
	mapPathMoveMapping["ed"]="eastdown";
	mapPathMoveMapping["wu"]="westup";
	mapPathMoveMapping["wd"]="westdown";
}

function loadLocationMap(){
	mapLocationNameId={};
	mapLocationIdPath={};
	listLocationId=new Array();
	
   var fso, f1, ts, s;
   var ForReading = 1;
   fso = new ActiveXObject("Scripting.FileSystemObject");
   ts = fso.OpenTextFile("C:\\mud\\fyvi\\allLocation.txt", ForReading);
   s = ts.ReadLine();

   while (!ts.AtEndOfStream){
	   var listLine=s.split("%");
	   if (s.indexOf("//")==-1 && listLine[5]!=null && listLine[5]!="" &&  listLine[5]!=undefined){
			var locName= listLine[0]+"-"+listLine[3];
			mapLocationNameId[locName]=listLine[2];
//			world.note("--->"+locName+":"+mapLocationNameId[locName]);
			mapLocationIdPath[listLine[2]]=listLine[5];
//			world.note("--->"+listLine[2]+":"+mapLocationIdPath[listLine[2]]);
//			world.note("--->"+listLine[2]+":"+mapLocationIdArea[listLine[2]]);
			listLocationId.push(listLine[2]);
			
			if (listLine[1]!=""){
//				world.note("---> area "+listLine[1]);
				var areaNames=mapAreaName[listLine[1]].split(",");
				var j=0;
				for (j=0;j<areaNames.length;j++){
					var areaLocName=areaNames[j]+listLine[0];
					var areaLocId=mapAreaLocName[areaLocName];
					if (areaLocId == null || areaLocId=="" ||areaLocId== undefined ){
						mapAreaLocName[areaLocName]=listLine[2];
					}else{
						mapAreaLocName[areaLocName]="duplicated";
//						world.note("---> loading "+areaLocName+","+listLine[2]);
					}
				}
			}
	   }
	   s = ts.ReadLine();
   }
   ts.Close();
   world.note("---> loading loadLocationMap completed with "+listLocationId.length+" locations");
}

function findLocationsByArea(area){
	var ret=new Array()
	for (i = 0; i < listLocationId.length; i++) {
		var id=listLocationId[i];
//			world.note("---> findLocationsByArea for "+area+":"+id);
		if (id.indexOf(area+"/")==0){
			ret.push(id);
//			world.note("---> findLocationsByArea for "+area+":"+id);
		}
	}
	return ret;
}

function queryMovePathById(id){
	var path=mapLocationIdPath[id];
	var area=id.split("/")[0];	
	if (path ==null || path =="" || path =="undefined"){
		world.note("---> path not found for id:"+id);
		return "";
	}else if (path.indexOf("+")<0){
		//start location now, return
		return path;
	}else{
		//linked to another location
		var pid=area+"/"+path.split("+")[0];
		return queryMovePathById(pid)+";"+path.split("+")[1];
	}	
}

function parsePathActionForMission(path,area){
	var ret=new Array();
	var paths=path.split(";");
	var j=0;
	for (j=0;j<paths.length;++j){
		var move=paths[j];
		if (move=="m1" || move=="m2" || move=="m3" || move=="m4" )
			ret.push(move+"-"+area);
		else if (move.indexOf("k ")==0)
			ret.push(move.replace("k ","missionKillOther "));
		else if (move=="p")
			ret.push("missionPoke");
		else if (move.indexOf("po ")==0)
			ret.push(move.replace("po ","missionPokeOther "));
		else if (mapPathMoveMapping[move]!=null && mapPathMoveMapping[move]!="")
			ret.push (mapPathMoveMapping[move]);
		else
			ret.push (move);
	}
	return ret.join(";");
}

function generateMissionActionMove(mpath){
	var moves=mpath.split(";");
	var move="";		
	for (var i=0;i<moves.length;i++){
		if (moves[i].indexOf("m1")==0 ||moves[i].indexOf("m2")==0 ||moves[i].indexOf("m3")==0||moves[i].indexOf("m4")==0){
			world.execute(moves[i]);
//			addMove2(moves[i]);
//			move="";
//		}else if (moves[i].indexOf("aasee")==0){
//			addMove2(moves[i]+";whisper");
//			move="";
		}else if (moves[i].indexOf("-")>0 ||  moves[i].indexOf("checkBusy")>=0 || moves[i].indexOf("umk")>=0 || moves[i].indexOf("smk")>=0 
			|| moves[i].indexOf("waitSec")>=0 || moves[i].indexOf("mission")==0){
			if (move!=""){
				addMove2(move+";whisper");
				addMove2(moves[i]);
				move="";
			}else{
				addMove2(moves[i]);
			}
		}else if ( moves[i].indexOf("#")>=0){
			if (move!=""){
				addMove2(move+";whisper");
				addMove2(moves[i]+";whisper");
				move="";
			}else{
				addMove2(moves[i]+";whisper");
			}
		}else if (moves[i].indexOf("auto")>=0){
			if (move!=""){
				addMove2(move+";"+moves[i]);
				move="";
			}else{
				addMove2(moves[i]);
			}
		}else{
			if (move==""){
				move=moves[i];
			}else{
				move=move+";"+moves[i];
			}
			if (move.split(";").length>=7){
				addMove2(move+";whisper");
				move="";
			}
		}
	}	
	if (move!="")
		addMove2(move+";whisper");
	
}


function loadGhostNpcMap(){
   var fso, f1, ts, s;
   var ForReading = 1;
   fso = new ActiveXObject("Scripting.FileSystemObject");
   ts = fso.OpenTextFile("C:\\mud\\fyvi\\ghostNpc.txt", ForReading);
   s = ts.ReadLine();
   while (!ts.AtEndOfStream){
	   var listLine=s.split(",");
	   if (s.indexOf("//")==-1){
		   mapGhostNpc[listLine[0]]=listLine[1];
	   }
	   s = ts.ReadLine();
   }
   ts.Close();
   world.note("---> loading mapGhostNpc completed");
}

function writeMissionLog(log){
   var fso, f, r
   var ForReading = 1, ForWriting = 2;
   fso = new ActiveXObject("Scripting.FileSystemObject");
   f = fso.OpenTextFile("c:\\mud\\fyvi\\mission.log", 8, true);
   f.WriteLine(new Date()+":"+log);
   f.Close();
}


//end of auto quest script

//end of script file