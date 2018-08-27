 // Room: waterpath.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "������"); 
        set("long", @LONG
һ���ٲ��ӽ�����к���£����齦�񣬺���������ٲ��·��۳�һ��ˮ̶��̶
ˮ΢������Ȼ��������ٲ�ֻ����ߣ�ȴ��һ�ֶ�ׯ��������������ӯӯ��ˮ��΢
΢��������˵�����������峺���ɰ���������ȴ��̶ˮ�ĺ��䣬�̲�ס����ȥ��Ӿ��
LONG);
        
        set("indoors", "yinghe");
        set("exits",([
        "east":__DIR__"riverroad2",
        "west":__DIR__"waterhole",
        ]) );
        //}} 
        setup();
        
} 
void init(){
        add_action("do_swim", "swim");
} 
int do_swim(){
        object me, dragon;
        
        me = this_player();
        dragon = present("water dragon", this_object());
        if(objectp(dragon)){
                return notify_fail("����������ˮ�����ΰɡ�\n");
        }
        if(me->is_busy() || me->is_fight()){
                return notify_fail("������æ��\n");
        }
        if (me->query("attribute/mark") == "fire" && me->query_temp("attribute") != "water"){
                message_vision("�����̶ˮ��$N�е�һ��ʹ����$NѸ���뿪̶ˮ��\n", me);   
                return 1;
        }
        message_vision("$NԾ��̶�ڣ������̶ˮ��$N����Ȼһ��\n", me);
        me->start_busy(4);
   call_out("recover", 4, me);
        return 1;
} 
void recover(object me){
    int gin,kee,sen;
    if(!me) return;
    gin=(int)me->query("max_gin");
    kee=(int)me->query("max_kee");
    sen=(int)me->query("max_sen");
        if( me && environment(me) == this_object()){
                message_vision("$N�ľ�����ȫ�ָ��ˣ���\n", me);
                me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
                me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
        if(!random(30)) me->delete_temp("jumpinpool");
        }
        return;
}
