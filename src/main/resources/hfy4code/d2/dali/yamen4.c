inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ǵ�����Ѳ�����ţ���������Ա�����������Ｉ�ã�����ᣩ��Ҫ���ɷ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"paifang",
]));
        set("objects", ([
//        __DIR__"npc/governor" : 1,
                        ]) );

        set("coor/x",-810);
        set("coor/y",-680);
        set("coor/z",80);
        setup();
}
void init()
{
add_action("do_jina","jina");
}
int gethim(object target,object me)
{
        if(!target || !me ) return 1;
        if(environment(me) == this_object())
        {
        message_vision("$Nһ�仰��˵���Ҵ�ææ���뿪�ˡ�\n",target);
        target->move(this_object());
        message_vision("$N����������Ѻ�˽�����\n",target);
        if(me){
        me->kill_ob(target);
        target->kill_ob(me);
                }
        return 1;
        }
        return 1;
}
int do_jina(string arg)
{
        object me, target;
        int exp, stra,leader,factor;
        if(!arg)
        return notify_fail("��Ҫ�����˭��\n");
        me = this_player();
        if((string) me->query("class") != "dali" )
        return notify_fail("�㲻�Ǵ�����Ա�����ɼ����ɷ���\n");
        if( me->is_busy() )
                return notify_fail("������һ��������û����ɣ�����ץ�á��� \n");
        if((int) me->query("sen") < 50 )
        return notify_fail("������񲻹���\n"); 
        me->start_busy(4);
        me->add("sen",-50);
        if(!objectp(target = find_living(arg)))
        return notify_fail("�Ҳ�������Ҫ���ɷ���\n");
        if( interactive(target) || !environment(target))
        return notify_fail("�Ҳ�������Ҫ���ɷ���\n");
        if( target->query("no_arrest") )
        return notify_fail("�Ҳ�������Ҫ���ɷ���\n");
 if( target->query("id")=="heiyi ren"&& random(this_player()->query("kar"))<30 )
        return notify_fail("�Ҳ�������Ҫ���ɷ���\n");
          if(target->query_temp("netdead"))
        return notify_fail("���棺�㲻����ץ�ö��ߵ���ң�\n");
        message_vision("$N����������������ǣ�����$n������������\n",me,target);
        exp = (int) target->query("combat_exp");
        stra = (int) me->query_skill("strategy",1);
        leader = (int) me->query_skill("leadership",1);
        factor = stra/10 * stra/10 * leader/10 * leader;
        factor = factor + (((int) me->query("combat_exp") ) - 2000 )/1000;                      
        if( random(factor) <= exp)
        return notify_fail("�������ڵ��������������Լ���"+target->query("name")+"��\n");
        call_out("gethim",5,target,me);
        return 1;
}
int valid_leave(object me, string dir)
{
        if(me->is_fighting())
        return notify_fail("�����ڲ����뿪��\n");
        return 1;
}