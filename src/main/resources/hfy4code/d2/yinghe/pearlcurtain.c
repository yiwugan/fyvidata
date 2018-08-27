 // Room: snakehall.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "��������"); 
        set("long", @LONG
��Ȼ�ӵ������������ã�һ�ſž�Ө�����鴹�Ҷ��£�������ص������������ƺ��ܼɵ���
Щ���顣����������ס��Ⱥ�ߣ�Ҳ��ס��Ⱥ������������������ƺ�����͵Ĺ�â������ӯӯ
�����͸�䣬������ã���������ƽ�͡�
LONG); 
        set("indoors","yinghe");
        set("item_desc", ([
                "curtain" : "Բ�����������ӫ��ɫ�Ĺ��������ժ������룩��\n",
                "����" : "Բ�����������ӫ��ɫ�Ĺ��������ժ������룩��\n",
        ]));
        set("exits",([
                "out" : __DIR__"snakehall",
                "enter" : __DIR__"snakebeauty",
        ]) );
        //}}
        set("pearl_amount", 2);
        setup(); 
} 
void init(){
        add_action("do_pick", "pick");
} 
int do_pick(string arg){
        object me, pearl;
        
        me = this_player();
        if(me->is_busy() || me->is_fighting()){
                return notify_fail("������æ��\n");
        }
        if(arg == "pearl" || arg == "����"){
                if(!query("pearl_amount")) {
                        return notify_fail("û�п����õ������ˡ�\n");
                }                       
                pearl = new(__DIR__"obj/pearl");
                if(objectp(pearl)){
                        message_vision("$N��������һ��ժ��һ�����顣\n", me);
                   pearl->move(me);
                        add("pearl_amount", -1);
                }
                return 1;
        } 
        return 0;
} 
void reset(){
        ::reset();
        if(!query("pearl_amount")) {
                set("pearl_amount", 2);
        }
        return;
}       
