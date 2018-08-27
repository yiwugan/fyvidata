 // unwield.c
inherit F_CLEAN_UP; 
int do_unwield(object me, object ob); 
int main(object me, string arg)
{
        object ob, *inv;
        string str;
        int i; 
        if( !arg ) return notify_fail("��Ҫ�ѵ�ʲ�᣿\n"); 
        if(arg=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        do_unwield(me, inv[i]);
                write("Ok.\n");
                return 1;
        } 
        if( !objectp(ob = present(arg, me)) )
                return notify_fail("������û������������\n");
        return do_unwield(me, ob);
} 
int do_unwield(object me, object ob){
        string str; 
        if( (string)ob->query("equipped")!="wielded" )
                return notify_fail("�㲢û��װ������������Ϊ������\n"); 
        if( ob->unequip() ) {
                if( !stringp(str = ob->query("unwield_msg")) )
                        str = "$N�������е�$n��\n";
//              message_vision(str, me, ob);
                F_EQUIP->selective_message(str,me,ob,"equip_msg");
                return 1;
        } else
                return 0;
} 
int help(object me)
{
  write(@HELP
ָ���ʽ : unwield all || <��Ʒ��>
 
���ָ������������е�������
 
HELP
    );
    return 1;
}
    
