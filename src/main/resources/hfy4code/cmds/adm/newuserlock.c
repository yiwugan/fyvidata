 // wizlock.c
inherit F_CLEAN_UP; 
int main(object me, string arg)
{
        int lvl=0; 
        if( me!=this_player(1) ) return 0;
        if( wiz_level(me) < wiz_level("(arch)") )
                return notify_fail("�����ʦ�ȼ�̫�ͣ�û��ʹ�����ָ���Ȩ����\n");
        if( !arg || arg=="" )
                return notify_fail("ָ���ʽ��newuserlock <1|0>\n"); 
        if( sscanf(arg, "%d", lvl)!=1 ) lvl = atoi(arg);
        seteuid(getuid());
        if( LOGIN_D->set_newuser_lock(lvl) ) {
                write(sprintf("\n��ֹ���˽�����Ϸ\n"));
                                
        } else
                write(sprintf("\n�������˽�����Ϸ\n"));
                return 1;
} 
int help (object me)
{
        write(@HELP
ָ���ʽ: newuserlock <1|0>
 
�����µ�ʹ���߽�����Ϸ�� 
 
HELP
);
        return 1;
}
   
