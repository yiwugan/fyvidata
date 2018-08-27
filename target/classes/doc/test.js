
var q=listQuestActiveQueue.pop();
world.note("---> quest target:"+q);

if (q==undefined){
//no quest available
world.note("---> quest not available, wait for 20 seconds");
world.doafterspecial(20,"resumeQuest",10);
var qc=world.getvariable("varQuestCancelCount");
world.note("---> current quest cancel count "+qc);
qc=parseInt(qc)+1;
if (qc<4){
world.execute("tt team-quest-cancel");
world.setvariable("varQuestCancelCount",qc);
world.doafterspecial(5,"tt quest-return-start",10);
}

}else{
//available quest
var path=queryQuestPath(q);
if (path==null){
//quest path not setup yet, skip it
world.note("---> quest path not found, skip "+q);
world.setvariable("varQuestCurrentTarget",q);
world.execute("questMissing");
world.doafterspecial(1,"goNextQuest",10);
}else{
//quest path found
world.setvariable("varQuestCurrentTarget",q);
//check if need to ghost directly
var type=world.getvariable("varQuestType");
if (type=="kill" && arrayContains(listQuestGhost,q)){
//ghost quest way
world.execute("goGhostKill");
}else{
//quest path way
//setup return item
world.note("---> quest path:"+path);
if (path.indexOf("questKill")>=0 || path.indexOf("questPoke")>=0){
world.setVariable("varQuestReturnItem","corpse");
}else{
var iename=queryQuestItemName(q);
world.setvariable("varQuestReturnItem",iename);
}
//check if need to clear shaolin mark
//shaolin hate doesn't matter, skip for now
var needClearShaolin=0;
if (path.indexOf("-clearShaolin")>0){
//needClearShaolin=1;
path=path.replace("-clearShaolin","");
}

initMove();
addMove2("smk2");
if (path.indexOf("goo")==0){
//fly path, setup fly broken command 
world.setvariable("varBreakCommand","questFlyBroken");
}else if (path.indexOf("get corpse;goo")==0){
//fly path, setup fly broken command 
world.setvariable("varBreakCommand","questFlyBroken");
//get corpse for item return
addMove2("north;enter;get corpse;out;south;whisper");
}else{
//walk only path
path="north;"+path;
}

generateQuestActionMove(path);
if (needClearShaolin==1)
  generateQuestClearShaolinMove();
else
  generateQuestPostMove();
startMove(false);

}
}
}