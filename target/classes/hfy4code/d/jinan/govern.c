 inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�����ǳ�͢���裬��������ľ��׶�������������״��������������һ�ž�
��ľ���������и�С��Ͱ��������ż�����֪����ӡ����ǩ��ľ�����̫ʦ��������
ѩ��Ƥ���κ������Ϻ�������ͼ����������ң�
                                �������
����͢���ٶ������ⷢ������������
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"street5",
        "south" : __DIR__"shufang",
        "west" : __DIR__"xiangfang",
    ]));
    set("objects", ([
        __DIR__"npc/yayi0" : 1,
        __DIR__"npc/yayi1" : 2,
        __DIR__"npc/yayi" : 2,
        __DIR__"npc/yayi2" : 2,
    ]) );
        set("coor/x",30);
        set("coor/y",1880);
        set("coor/z",0);
        setup(); 
} 
void init()
{
        object xing;
        mixed *current_time;
        
        current_time=NATURE_D->get_current_time();
        if(xing=present("xing rui",this_object()))
        {
                if(current_time[5]<480||current_time[5]>1200)
                {
                   message_vision("�����Ȼ������γ���һ�㣬˵������ԭ������ôҹ�ˣ��ǻؼҵ�ʱ���ˡ���\n",this_player());
                        message_vision("�������������˳�ȥ��\n",this_player());
                        destruct(xing);
                }
                else if(current_time[5]>1080)
                {
                        message_vision("��������$N�ļ��˵������̫���ˣ��������������ɡ���\n",this_player());
                        message_vision("�����������������ȥ�ͽ�ʦү�����Ѱɡ���ת���뿪��\n",this_player());
                        destruct(xing);
                }
        }
        else
                if(current_time[5]>480&&current_time[5]<960)
                {
                        xing=new(__DIR__"npc/xing");
                        xing->move(this_object());
                        message_vision("���������˵�����������������á���������\n",xing);
                }
                
        add_action("do_arrest","arrest");
        
} 
int do_arrest(string arg)
{
        
        object me, target,xing;
        int exp, stra,leader,factor,mysen;
        if(!arg)
                return notify_fail("��Ҫ�����˭��\n");
        me = this_player();
        if((string) me->query("class") != "official" )
                return notify_fail("�㲻�ǳ�͢��Ա�����ɼ����ɷ���\n");
        if (me->query("marks/�ٸ�/����"))
                return notify_fail("����ָ��ǧ������Ĵ󽫣�ץ���˵��»����������ɷ��Ĺ�Աȥ���ɡ�\n");
        if(!xing=present("xing rui",this_object()))
                return notify_fail("�ܲ�ͷ���ڣ��޷�����в����ˡ�\n");
        mysen=(int) me->query("sen");
        if( mysen< 150 )
                return notify_fail("������񲻹����޷��¾в������\n");       
        if (me->is_busy())
           return notify_fail("������û�գ���\n");
        
        if(!objectp(target = find_living(arg)))
                return notify_fail("���ܲ�ͷ����˵������С�����ܣ�û�й�������˵��������޷��в�����\n");
        if( !userp(target) && !environment(target))
                return notify_fail("���ܲ�ͷ����˵������С�����찵�ã������ƺ���Ǳ�������ˣ��Ҳ�����������Щʱ����˵�ɡ���\n");
        if( userp(target) || !environment(target))
                return notify_fail("���ܲ�ͷ����˵��������ˡС�˶��ԣ����˲��޹��������ǵ����˴������˰ɡ���\n");
        if( target->query("no_arrest") )
                return notify_fail("���ܲ�ͷ̾�˿���˵������������֮�������ٸ���Ͻ��Χ�������������������찡����\n");
        if (target->is_fighting())
                return notify_fail("���ܲ�ͷ��˼Ƭ��˵�������Ѿ��г���������ˣ������Ҿ�����䡣\n");
        if (environment(target)==this_object())
                return notify_fail("���ܲ�ͷ�����˵��С���Ѿ��Ѵ��˾��ù鰸�ˡ�\n");           
                
        mysen=mysen*3/100;
        me->add("sen",-mysen);
        
        message_vision("$N����������������ǣ�����$n������������\n",me,target);
        message_vision("$N˵������������ڣ�������ȥִ��"+me->query("name")+"���˵��������\n",xing);
        
        exp = (int) target->query("combat_exp");
        stra = (int) me->query_skill("strategy",1);
        leader = (int) me->query_skill("leadership",1);
        factor = stra * stra / 10 * leader / 10 * leader / 10;
        factor += ((int) me->query("combat_exp") - 2000 )/1000;                 
        if( random(factor) <= exp) {
                me->start_busy(3);
                return notify_fail("���ܲ�ͷ����˵������С�����ܣ���"+target->query("name")+"�����ˣ�\n");
        }
        
        me->start_busy(2);
        call_out("gethim",5,target,me);
        return 1;
} 
int gethim(object target,object me)
{
        if(!target || !me ) return 1;
        if (target->is_fighting()) {
                tell_object(me,"���ܲ�ͷ����˵������С�����ܣ���"+target->query("name")+"�����ˣ�\n");
           return 1;
        }
        if(environment(me) == this_object())
        {
        message_vision("��ȻһȺ������˹�����������˵�ͽ�$N�����ˡ�\n",target);
        target->move(this_object());
        message_vision("$N���ٱ�Ѻ�˽�����\n",target);
        if(me){
        me->kill_ob(target);
        target->kill_ob(me);
        target->start_busy(3);
                }
        return 1;
        }
        return 1;
} 
valid_leave(object me,string dir)
{
        object xing;
        
        if((dir =="south" || dir == "west") && me->query("class")!="official"
                &&xing=present("xing rui",this_object()))
                return notify_fail("�������ȵ����������ô���Ҫ�صأ�����\n");
        return 1;
}  
