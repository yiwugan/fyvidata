 // remove.c
#include <ansi.h> 
inherit F_CLEAN_UP; 
int     do_remove(object me, object ob);
//int   selective_message(string msg,object me,object you, string flag); 
int main(object me, string arg)
{
        object ob, *inv;
        int i; 
        if( !arg ) return notify_fail("你要脱掉什麽？\n"); 
        if(arg=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        do_remove(me, inv[i]);
                write("Ok.\n");
                return 1;
        } 
        if( !objectp(ob = present(arg, me)) )
                return notify_fail("你身上没有这样东西。\n");
        return do_remove(me, ob);
} 
int do_remove(object me, object ob)
{
        string str; 
        if( (string)ob->query("equipped")!="worn" )
                return notify_fail("你并没有装备这样东西。\n"); 
        if( ob->unequip() ) {
                if( !stringp(str = ob->query("unequip_msg")) )
                        switch(ob->query("armor_type")) {
                                case "cloth":
                                case "armor":
                                case "surcoat":
                                case "boots":
                                        str = YEL "$N将$n脱了下来。\n" NOR;
                                        break;
                                case "bandage":
                                        str = YEL "$N将$n从伤口处拆了下来。\n" NOR;
                                        break;
                                default:
                                        str = YEL "$N卸除$n的装备。\n" NOR;
                   } 
                F_EQUIP->selective_message(str,me,ob,"equip_msg");                      
                
                return 1;
        } else
                return 0;
}
/*
int     selective_message(string msg,object me,object you, string flag) {
        
        string my_gender, my_name, your_name;
        string str1, str3;
        object *exclude= ({});
        int my_flag;
        int i;
                
        my_name= me->name();
        my_gender = me->query("gender");
        str1 = replace_string(msg,  "$P", gender_self(my_gender));
        str1 = replace_string(str1, "$N", gender_self(my_gender));
        str3 = replace_string(msg,  "$P", my_name);
        str3 = replace_string(str3, "$N", my_name);
        
        your_name= you->name();
        str1 = replace_string(str1, "$n", your_name);
        str3 = replace_string(str3, "$n", your_name);
        
        my_flag = me->query("env/"+flag);
        exclude=filter_array(all_inventory(environment(me)),(: $1->query("env/"+$2)>1 :),flag); 
        exclude += ({me});
        message("vision", str3, environment(me),exclude); 
        if (my_flag !=1 && my_flag !=3) 
                message("vision", str1, me);
        else message("vision","\n",me);
                                        
        return 1; 
}*/
         
int help(object me)
{
  write(@HELP
指令格式 : remove all | <物品名称>
 
这个指令让你脱掉身上某件防具.
 
HELP
    );
    return 1;
}
        
