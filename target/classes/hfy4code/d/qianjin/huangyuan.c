#include <ansi.h>
inherit ROOM;
void warning(object me);
void capture(object me);
void create()
{
        set("short", "��԰");
        set("long", @LONG
ת���ɻ�������ɫٿȻһ�䣬��ɫ���ԣ���ѻ�ӹ���С·�ϻĲ�û����������
Ҳ�����˿�Ҷ����ͷ�Ŀ�ľ����С¥һ�ǣ���ϡ���ǵ���С��̽������ѧ��������
С�������ȴ���ѻķϣ�����������������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"hehuadang2",
]));
        set("outdoors","qianjin"); 
        set("coor/x",-60);
        set("coor/y",-20);
        set("coor/z",0);
        setup();
        //replace_program(ROOM);
}
void init()
{
        object me = this_player();
        
        add_action("do_search","search");
        
        remove_call_out("warning");
        remove_call_out("capture");
        if (me->query_per() > 26 
                && me->query("age") >13 
//        && !NATURE_D->is_day_time()
                && me->query("age") <26 
                && !me->query_temp("afei_on_the_way")
                && me->query("combat_exp")>300000 
                && me->query("gender") == "Ů��" ) 
        {
                call_out("warning", 10, me);
   }
        
}
void warning(object me) {
        if (environment(me) == this_object() ) {
        tell_object(me, WHT"\n��԰�ﺮѻ��������Ҷ������һ��Σ�յ�Ԥ��������÷ǳ�������\n\n"NOR);
                call_out("capture", 5, me);
        }
        
} 
void capture(object me) {
        object room;
        if (environment(me) == this_object() ) { 
        message_vision(HIB"\n��ľ���к�Ȼ����һ������ķ磬���쬵��������Ϲι������������ۣ�ͻȻ����\n"NOR, me);
        message_vision(HIB"�ƺ��и���Ӱվ��$N�����$N�Ȼһ��������ת��ȴ�ѱ�������Ѩ����\n\n��Ӱ��$NЮ�����£����Ƽ��������˳�ȥ������\n\n"NOR, me);
                room=find_object(AREA_QIANJIN"basement");
                if(!objectp(room))
                        room=load_object(AREA_QIANJIN"basement");
                me->set_temp("marks/meihuadao", 1);
                me->move(room);         
             message_vision(HIR"\n÷������$N�����˵����ҽ������С���ϣ�һ��Ī����״����ζϮ����$N��Ϣһ\n�ϣ����˹�ȥ��\n"NOR,me);
             me->unconcious();
        }
} 
int do_search() {
        object me = this_player(); 
        if (me->query_temp("afei_on_the_way") ) {
                tell_object(me, WHT"\n��԰�ﺮѻ��������Ҷ������һ��Σ�յ�Ԥ��������÷ǳ�������\n\n"NOR);
                
                message_vision("$N������Ҷ�����ֵ�����һ�����ڡ�\n", me);
                if( !query("exits/down") ) {
                        set("exits/down", __DIR__"basement");
                        call_out("close_path", 1);                
                        
                }
                return 1;
        }
        return 0;
}  
void close_path()
{
        if( !query("exits/down") ) return;
        message("vision",
"һ��紵��ƬƬ��Ҷ���׷���������£��ڱ��˵��ϵĶ��ڡ�\n",
                this_object() );
                delete("exits/down");
}   
