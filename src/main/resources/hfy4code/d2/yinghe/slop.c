 // Room: slop.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "��ɫ����"); 
        set("long", @LONG
����һƬ����Ĳݵأ�����������ģ���������һ��ε������µĺ�����
������Ư���ŵĵ���������㣬�Լ���һ����ɫ�������԰׵Ŀռ����Щ���
��������ϸ������ɫ���ƺ���֯�����ص���ɫ��������һ�����������������У�
�ϱ�ȴ��һƬ��嫵�ɳ����һ��������������ɳ֮�ϡ�
LONG); 
        //{{ --- by MapMaker
        set("type","street");
        set("exits",([
        "west":__DIR__"garden",
        "south":__DIR__"woodroad",
        "north":__DIR__"dragon_den",
        ]) );
        //}}
        set("item_desc", ([
                "�ݵ�" : "ï�ܵĲݵ���������һ����ֵ����١�������𡡣����壩\n",
                "grass" : "ï�ܵĲݵ���������һ����ֵ����١�������𡡣����壩\n",
        ]));
        set("vine", 1);
        set("indoors", "yinghe");
        setup();
} 
void init(){
        add_action("do_chop", "chop");
} 
int do_chop(string arg){
    object obj;
    object me; 
    if(arg && (arg=="vine" || arg=="����")){
        me = this_player();
        obj = me->query_temp("weapon");
        if( !obj ) {
            write("������֣���ô����\n");
            return 1;
        }
        if( obj->query("flag") == 4){
            if(query("vine")) {
                object ob;
                message_vision(sprintf(
                    "$N�Ӷ�%s��������һ�����������ܡ�\n",obj->name()),me);
                delete("vine");
                ob=new(__DIR__"obj/vine");
                ob->move(me);
            } else {
            message_vision(sprintf(
            "$N�����е�%s����ɫ�Ĳݴԡ�\n",obj->name()), me);
                }
        } else {
                message_vision(sprintf(
            "$N�����е�%s�����������һ���ҿ���\n",obj->name()), me);
        }
    }
    else write("��Ҫ��ʲô��\n");
    return 1;
} 
void reset(){
        ::reset();
        set("vine", 1);
}   
