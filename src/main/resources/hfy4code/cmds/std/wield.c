 // wield.c
inherit F_CLEAN_UP; 
int do_wield(object me, object ob); 
int main(object me, string arg)
{
        object ob, *inv;
        int i, count; 
        if( !arg ) return notify_fail("你要装备什麽武器？\n"); 
        if(arg=="all") {
                inv = all_inventory(me);
                for(count=0, i=0; i<sizeof(inv); i++) {
                        if( inv[i]->query("equipped") ) continue;
                        if(do_wield(me, inv[i]) ) count ++;
                }
                write("Ok.\n");
                return 1;
        } 
        if( !objectp(ob = present(arg, me)) )
                return notify_fail("你身上没有这样东西。\n"); 
        if( ob->query("equipped") )
                return notify_fail("你已经装备著了。\n"); 
        return do_wield(me, ob);
} 
int do_wield(object me, object ob)
{
        string str; 
        if (ob->query("class"))
        if (ob->query("class")!= me->query("class"))
                return notify_fail("你的门派武功不适合用这件武器。\n");
        
        if (ob->query("experience"))
        if (ob->query("experience")>me->query("combat_exp"))
                return notify_fail("你的实战经验太低，发挥不了这件武器的威力。\n");
        
        if (ob->query("strength"))
        if (ob->query("strength")>me->query_str())
                return notify_fail("你的臂力太弱，举不起这件武器。\n");
        
        if (ob->query("agility"))
        if (ob->query("agility")>me->query_agi())
           return notify_fail("你不够敏捷，无法将这件武器运转如意。\n");
                
        if (ob->query("score"))
        if (ob->query("score")<me->query("score"))
                return notify_fail("这件武器太过阴毒，你这样有身份的人不适合用吧。\n");
                
        if( ob->wield() ) {
                if( !stringp(str = ob->query("wield_msg")) )
                        str = "$N装备$n作武器。\n";
//              message_vision(str, me, ob);
                F_EQUIP->selective_message(str,me,ob,"equip_msg");
                return 1;
        } else
                return 0;
} 
int help(object me)
{
        write(@HELP
指令格式：wield <装备名称>
 
这个指令让你装备某件物品作武器, 你必需要拥有这样物品.
 
HELP
    );
    return 1;
}    
