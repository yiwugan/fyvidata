 inherit ROOM;
void create()
{
        set("short", "Ľ��ׯ԰");
        set("long", @LONG
��Դ��һ�ǲ�֪��ʱ����һ��СС��ׯ԰����ɫ��Ժǽ����ɫ���߶������ܾ�
���ĵġ�����Ĵ���΢���ţ��ſ�������һ�����������顰Ľ�ݡ����֡�ׯ԰����ǰ
��һƬ��ɫ�Ĳ�ƺ����������һƬ���֡�
LONG
        ); 
    set("exits", ([ /* sizeof() == 4 */
                "south" : AREA_TAOYUAN"road3",
        ]) ); 
        set("item_desc", ([
                "door" : "�������ֻ�������ţ��ƺ�����һ�ƾͿ��ˡ�\n",
                "��" : "�������ֻ�������ţ��ƺ�����һ�ƾͿ��ˡ�\n",
        ]) ); 
        set("outdoors","murong");
    set("coor/x",210);
        set("coor/y",-30);
        set("coor/z",0);
        setup(); 
} 
void init() { 
        add_action("do_push", "push");
}  
void close_path()
{
        if( query("exits/north") ) {
    message("vision","��������������ϡ�\n",this_object() );
    delete("exits/north");
    }
} 
int do_push(string arg)
{
        object me;
    me = this_player();
    if( arg=="door" || arg =="��") {
        message_vision("$N����������������һ�ƣ�֨��������һ���ſ��ˡ�\n", me);
                set("exits/north", __DIR__"menkou");
           call_out("close_path", 5);
        } else {
                write("��Ҫ��ʲô�أ�\n");
        }
        return 1;       
 }  
