// /cmds/stdget.c 
// modified by siso at JUN 6, 2005 
// can get either "name" or "id" 
// modified by justdoit at 11.1 2001 
// fix the bug that can not get 1 piece from xxx 
#include <ansi.h> 
inherit F_CLEAN_UP; 
object present(mixed str, object env); 
int do_get(object me, object ob, object env); //modified 
void create() { seteuid(getuid()); } 
int main(object me, string arg) 
{ 
string from, item; 
object obj, *inv, env, obj2; 
object *my_inv, my_item; 
int i, j, amount, num; 
string arg1, from1; 
if( !arg ) return notify_fail("你要捡起什麽东西？\n"); 
if( me->is_busy() ) 
return notify_fail("你上一个动作还没有完成！\n"); 
// prevent people using get xyz from wall 0 
// prevent people using get xyz from wall 1 
if ( sscanf(arg, "%s from %s %d", arg1, from1, num)==3) { 
if (num==0 || num ==1) 
return notify_fail("不必或不能使用get xxx from xxx 0/1。\n"); 
} 
// Check if a container is specified. 
if( sscanf(arg, "%s from %s", arg, from)==2 ) { 
// 找容器：身上的物品－所初房间中的物品 by siso_20050606 
env = present(from, me); 
if(!env) env = present(from, environment(me)); 
if(!env) return notify_fail("你找不到 " + from + " 这样东西。\n"); 
if( !env->is_corpse() && env->is_character() && (wiz_level(me) <= wiz_level(env))) 
return notify_fail("你的管理等级必须比对方高，才能搜身。\n"); 
} else env = environment(me); 
// check if this thing is locked or whatsoever any tricks invovled 
if( (int) env->is_closed()) 
return notify_fail( "你要先把" + env->name() + "打开。\n"); 
// Check if a certain amount is specified. 
if(sscanf(arg, "%d %s", amount, item)==2) { 
if( !objectp(obj = present(item, env)) ) 
return notify_fail("这里没有这样东西。\n"); 
if( !obj->query_amount() ) 
return notify_fail( obj->name() + "不能被分开拿走。\n"); 
if( amount < 1 ) 
return notify_fail("东西的个数至少是一个。\n"); 
if( amount > obj->query_amount() ) { 
return notify_fail("这里没有那麽多的" + obj->name() + "。\n"); 
} else if(amount == (int)obj->query_amount()) { 
return do_get(me, obj, env); //modified 
} else { 
obj->set_amount( (int)obj->query_amount() - amount ); 
obj2 = new(base_name(obj)); 
obj2->set_amount(amount); 
obj2->move(me); //modified 
// Counting precise amount costs more time. 
if( me->is_fighting() ) me->start_busy(3); 
return do_get(me, obj2, env); //modified 
} 
} 
// Check if we are makeing a quick get. 
if(arg=="all") { 
if( me->is_fighting() ) return notify_fail("你还在战斗中！只能一次拿一样。\n"); 
if( !env->query_max_encumbrance() ) return notify_fail("那不是容器。\n"); 
inv = all_inventory(env); 
if( !sizeof(inv) ) 
return notify_fail("那里面没有任何东西。\n"); 
for(i=0; i<sizeof(inv); i++) { 
// if(inv[i]->query("owner") && inv[i]->query("owner") != me->query("id")) continue; 
if( (inv[i]->is_character() && !inv[i]->query("yes_carry")) || inv[i]->query("no_get") || inv[i]->query("lore")) continue; 
do_get(me, inv[i], env); //modified 
} 
write("Ok。\n"); 
return 1; 
} 
if( !objectp(obj = present(arg, env)) || (living(obj) && !(int)obj->query("yes_carry"))) 
return notify_fail("你附近没有这样东西。\n"); 
// if(obj->query("owner") && obj->query("owner") != me->query("id")){ 
// return notify_fail("这样东西不属于你，你无法拿起。\n"); 
// } 
if( obj->query("no_get") ) 
return notify_fail("这个东西拿不起来。\n"); 
// lore item, you can only own one in your inventory at a time 
if ( obj->query("lore")) { 
my_inv = all_inventory(me); 
for(j=0;j<sizeof(my_inv);j++){ 
my_item = my_inv[j]; 
if(obj->query("name")==my_item->query("name") 
&& my_item->query("lore")) 
return notify_fail("这样东西你最多只能有一件。\n"); 
} 
} 

return do_get(me, obj, env); //modified 
} 

int do_get(object me, object obj,object env) //modified 
{ 
object old_env, *enemy; 
int equipped; 
object target; 
string prep; 
target = me; 
if( !obj ) return 0; 
old_env = env; //modified 
if( obj->is_character() && !obj->is_corpse()) { 
return notify_fail("你不能背负活物。\n"); 
// If we try to save someone from combat, take the risk :P 
} else { 
if( obj->query("no_get") ) return 0; 
} 
if( obj->query("equipped") ) equipped = 1; 
if( obj->query("yes_carry")) target = environment(me); 
if( obj->move(target) ) { 
if((int)obj->query("no_transfer") 
){obj->set("no_get",1); obj->set("no_drop",1);} 
if( me->is_fighting() ) me->start_busy(1); 
if( obj->is_character() && !obj->query("yes_carry")) 
message_vision( "$N将$n扶了起来背在背上。\n", me, obj ); 
else { 
if(old_env==environment(me)) prep = "捡起"; 
else if(old_env->is_character()) prep = "从" + old_env->name() + "身上" + (equipped? "除下" : "搜出"); 
else switch( old_env->query("prep") ) { 
case "on": 
prep = "从" + old_env->name() + "上拿起"; 
break; 
case "under": 
prep = "从" + old_env->name() + "下拿出"; 
break; 
case "behind": 
prep = "从" + old_env->name() + "后拿出"; 
break; 
case "inside": 
prep = "从" + old_env->name() + "中拿出"; 
break; 
default: 
prep = "从" + old_env->name() + "中拿出"; 
break; 
}; 
message_vision( sprintf("$N%s一%s$n。\n", prep, 
obj->query("unit")), me, obj ); 
} 
return 1; 
} 
else return 0; 
} 

// 覆盖present()这个efun,加入对"name"的比较 by siso_20050606 
object present(mixed str, object env) 
{ 
object *inv; 
int i; 

if( !env->query_max_encumbrance() ) 
return 0; 
inv = all_inventory(env); 
if( !sizeof(inv) ) 
return 0; 
if( str ) { 
str = replace_string(str, "$BLK$", BLK); 
str = replace_string(str, "$RED$", RED); 
str = replace_string(str, "$GRN$", GRN); 
str = replace_string(str, "$YEL$", YEL); 
str = replace_string(str, "$BLU$", BLU); 
str = replace_string(str, "$MAG$", MAG); 
str = replace_string(str, "$CYN$", CYN); 
str = replace_string(str, "$WHT$", WHT); 
str = replace_string(str, "$HIR$", HIR); 
str = replace_string(str, "$HIG$", HIG); 
str = replace_string(str, "$HIY$", HIY); 
str = replace_string(str, "$HIB$", HIB); 
str = replace_string(str, "$HIM$", HIM); 
str = replace_string(str, "$HIC$", HIC); 
str = replace_string(str, "$HIW$", HIW); 
str = replace_string(str, "$NOR$", NOR); 
} 
for(i=0; i<sizeof(inv); i++) { 
if ( str == inv[i]->name() || str == (inv[i]->query("id")) ) 
return inv[i]; 
} 
return efun::present(str, env); 
} 


int help(object me) 
{ 
write(@HELP 
指令格式 : get <物品> [from <容器>] 

这个指令可以让你捡起地上或容器内的某样物品. 
物品和容器都既可以使用英文ID也可以使用中文名字。 
如果物品或容器有颜色，请参照以下规则： 

get <颜色代码><物品名称>$NOR$ from <容器> 

<颜色代码> 
$BLK$ - 黑色 $NOR$ - 恢复正常颜色 
$RED$ - 红色 $HIR$ - 亮红色 
$GRN$ - 绿色 $HIG$ - 亮绿色 
$YEL$ - 土黄色 $HIY$ - 黄色 
$BLU$ - 深蓝色 $HIB$ - 蓝色 
$MAG$ - 浅紫色 $HIM$ - 粉红色 
$CYN$ - 蓝绿色 $HIC$ - 天青色 
$WHT$ - 浅灰色 $HIW$ - 白色 
HELP 
); 
return 1; 
}
