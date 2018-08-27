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
if( !arg ) return notify_fail("��Ҫ����ʲ�ᶫ����\n"); 
if( me->is_busy() ) 
return notify_fail("����һ��������û����ɣ�\n"); 
// prevent people using get xyz from wall 0 
// prevent people using get xyz from wall 1 
if ( sscanf(arg, "%s from %s %d", arg1, from1, num)==3) { 
if (num==0 || num ==1) 
return notify_fail("���ػ���ʹ��get xxx from xxx 0/1��\n"); 
} 
// Check if a container is specified. 
if( sscanf(arg, "%s from %s", arg, from)==2 ) { 
// �����������ϵ���Ʒ�����������е���Ʒ by siso_20050606 
env = present(from, me); 
if(!env) env = present(from, environment(me)); 
if(!env) return notify_fail("���Ҳ��� " + from + " ����������\n"); 
if( !env->is_corpse() && env->is_character() && (wiz_level(me) <= wiz_level(env))) 
return notify_fail("��Ĺ���ȼ�����ȶԷ��ߣ���������\n"); 
} else env = environment(me); 
// check if this thing is locked or whatsoever any tricks invovled 
if( (int) env->is_closed()) 
return notify_fail( "��Ҫ�Ȱ�" + env->name() + "�򿪡�\n"); 
// Check if a certain amount is specified. 
if(sscanf(arg, "%d %s", amount, item)==2) { 
if( !objectp(obj = present(item, env)) ) 
return notify_fail("����û������������\n"); 
if( !obj->query_amount() ) 
return notify_fail( obj->name() + "���ܱ��ֿ����ߡ�\n"); 
if( amount < 1 ) 
return notify_fail("�����ĸ���������һ����\n"); 
if( amount > obj->query_amount() ) { 
return notify_fail("����û��������" + obj->name() + "��\n"); 
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
if( me->is_fighting() ) return notify_fail("�㻹��ս���У�ֻ��һ����һ����\n"); 
if( !env->query_max_encumbrance() ) return notify_fail("�ǲ���������\n"); 
inv = all_inventory(env); 
if( !sizeof(inv) ) 
return notify_fail("������û���κζ�����\n"); 
for(i=0; i<sizeof(inv); i++) { 
// if(inv[i]->query("owner") && inv[i]->query("owner") != me->query("id")) continue; 
if( (inv[i]->is_character() && !inv[i]->query("yes_carry")) || inv[i]->query("no_get") || inv[i]->query("lore")) continue; 
do_get(me, inv[i], env); //modified 
} 
write("Ok��\n"); 
return 1; 
} 
if( !objectp(obj = present(arg, env)) || (living(obj) && !(int)obj->query("yes_carry"))) 
return notify_fail("�㸽��û������������\n"); 
// if(obj->query("owner") && obj->query("owner") != me->query("id")){ 
// return notify_fail("���������������㣬���޷�����\n"); 
// } 
if( obj->query("no_get") ) 
return notify_fail("��������ò�������\n"); 
// lore item, you can only own one in your inventory at a time 
if ( obj->query("lore")) { 
my_inv = all_inventory(me); 
for(j=0;j<sizeof(my_inv);j++){ 
my_item = my_inv[j]; 
if(obj->query("name")==my_item->query("name") 
&& my_item->query("lore")) 
return notify_fail("�������������ֻ����һ����\n"); 
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
return notify_fail("�㲻�ܱ������\n"); 
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
message_vision( "$N��$n�����������ڱ��ϡ�\n", me, obj ); 
else { 
if(old_env==environment(me)) prep = "����"; 
else if(old_env->is_character()) prep = "��" + old_env->name() + "����" + (equipped? "����" : "�ѳ�"); 
else switch( old_env->query("prep") ) { 
case "on": 
prep = "��" + old_env->name() + "������"; 
break; 
case "under": 
prep = "��" + old_env->name() + "���ó�"; 
break; 
case "behind": 
prep = "��" + old_env->name() + "���ó�"; 
break; 
case "inside": 
prep = "��" + old_env->name() + "���ó�"; 
break; 
default: 
prep = "��" + old_env->name() + "���ó�"; 
break; 
}; 
message_vision( sprintf("$N%sһ%s$n��\n", prep, 
obj->query("unit")), me, obj ); 
} 
return 1; 
} 
else return 0; 
} 

// ����present()���efun,�����"name"�ıȽ� by siso_20050606 
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
ָ���ʽ : get <��Ʒ> [from <����>] 

���ָ��������������ϻ������ڵ�ĳ����Ʒ. 
��Ʒ���������ȿ���ʹ��Ӣ��IDҲ����ʹ���������֡� 
�����Ʒ����������ɫ����������¹��� 

get <��ɫ����><��Ʒ����>$NOR$ from <����> 

<��ɫ����> 
$BLK$ - ��ɫ $NOR$ - �ָ�������ɫ 
$RED$ - ��ɫ $HIR$ - ����ɫ 
$GRN$ - ��ɫ $HIG$ - ����ɫ 
$YEL$ - ����ɫ $HIY$ - ��ɫ 
$BLU$ - ����ɫ $HIB$ - ��ɫ 
$MAG$ - ǳ��ɫ $HIM$ - �ۺ�ɫ 
$CYN$ - ����ɫ $HIC$ - ����ɫ 
$WHT$ - ǳ��ɫ $HIW$ - ��ɫ 
HELP 
); 
return 1; 
}
