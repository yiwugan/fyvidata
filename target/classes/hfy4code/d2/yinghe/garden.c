 // Room: garden.c --- by MapMaker
inherit ROOM;
void bird_attack(object me);
int bird_flee(object me);
void create()
{
        set("short", "��ľ��ݺ԰"); 
        set("long", @LONG
��ɫ��Ȼһ�䣬��ǰ����һƬ���̵����֣���䲻���滨��ݣ��ּ��ļ�Ư
���ŵ��������������㣬���������֮����������ҹݺ��ʱ��������������һ��
Сľ��ǰ������ʱ���ƺ���ֹͣ�ģ�һ�ж�������һ�����صĻҰ�ɫ�¡�
LONG); 
        //{{ --- by MapMaker 
        set("exits",([
                "east":__DIR__"slop",
                "northup" : __DIR__"gardenn",
                "southdown" : __DIR__"gardens",
        ]) );
        set("item_desc", ([
                "door" : "һ��Сľ�ţ��ƺ������ƿ����������裩\n",
                "Сľ��" : "һ��Сľ�ţ��ƺ������ƿ����������裩\n",
                "��" : "һ��Сľ�ţ��ƺ������ƿ����������裩\n",
                "tree" : "һ�ÿ���ڴ�С����ͦ�βԴ䡣������𡡣����壩\n", 
                "����" : "һ�ÿ���ڴ�С����ͦ�βԴ䡣������𡡣����壩\n", 
        ]));    
        
        set("objects", ([
                __DIR__"npc/bird_guard" : 4,
        ]));
        set("tree", 1);
        set("indoors", "linghe");
        setup();
} 
void init(){
        add_action("do_push", "push");
        add_action("do_chop", "chop");
} 
int do_chop(string arg){
    object obj, me;
    
    me = this_player();
        if(!query("bird_flee")) {
                bird_attack(me);
                return 1;
        }
    if(arg && (arg=="tree" || arg=="��")){
        obj = me->query_temp("weapon");
        if( !obj ) {
            write("������֣���ô����\n");
            return 1;
        }
        if( obj->query("flag") == 4){
            if(query("tree")) {
                object ob;
                message_vision(sprintf(
                    "$N�Ӷ�%s��ת�ۼ�һ��С���ͱ������ˡ�\n",obj->name()),me);
                delete("tree");
                ob=new(__DIR__"obj/tree");
                if(objectp(ob)){
                       ob->move(me);
                        }
            } else {
                                return notify_fail("û�к��ʵ����ˡ�\n");
                }
        } else {
                message_vision(sprintf(
            "$N�����е�%s��С����һͨ�ҿ���\n",obj->name()), me);
        }
    }
    else write("��Ҫ��ʲô��\n");
    return 1;
}
void close_path(){
        object room;
        room = find_object(__DIR__"woodcabin");
        if(!objectp(room)){
                room = load_object(__DIR__"woodcabin");
        }
        if( room->query("exits/east")){
                message("vision","֨ѽ������һ��ľ���������ˡ�\n",room );
           room->delete("exits/east");
    }
        if( query("exits/west") ) {
        message("vision","֨ѽ������һ��ľ���������ˡ�\n",this_object() );
        delete("exits/west");
    }
} 
int do_push(string arg){
        object me, *inv, bird, room;
        int i, j; 
    me = this_player();
    if(query("exits/west")){
        return notify_fail("���ǿ��ŵġ�\n");
    }
        if(!query("bird_flee")) {
                bird_attack(me);
                return 1;
        }    
    if( arg=="door" || arg =="��" || arg == "Сľ��") {
        message_vision("$N��Сľ���������һ�ƣ�֨��������һ���ſ��ˡ�\n", me);
                set("exits/west", __DIR__"woodcabin");
                room = find_object(__DIR__"woodcabin");
                if(!objectp(room)){
                        room = load_object(__DIR__"woodcabin");
                }
                room->set("exits/east", __DIR__"garden");
                call_out("close_path", 5);
        } else {
                write("��Ҫ��ʲô�أ�\n");
        }
        return 1;       
} 
void bird_attack(object me){
        object *inv, bird;
        int i, j;
        
        inv = all_inventory();
        j = 0;
        for(i=0; i<sizeof(inv); i++){
                if(inv[i]->query("id") == "nightingale"){
                   inv[i]->kill_ob(me);
                        j++;
                }
        }
        if(j < 4){
                for(i=0; i<random(4)+2; i++){
                        bird = new(__DIR__"npc/bird_guard");
                        if(objectp(bird)){
                                bird->move(this_object());
                        }
                        message_vision("�����㣬��ֻҹݺ��������������$N��ǰ��\n", me);
                        bird->kill_ob(me);
                }
        }
        return notify_fail("һȺҹݺ������ǰ�����ţ����������ȥ·��\n");
} 
int valid_leave(object who, string arg){
        object bird, *inv, *guard;
        int i, j;
        if(arg == "west"){
                if(query("bird_flee")) {
                        return 1;
                } else {
                        bird_attack(who);
                }
        }
        return 1;
} 
int bird_flee(object me){
        object *inv;
        int i, j;
        j = 0;
        inv = all_inventory();
        for(i=0; i<sizeof(inv); i++){
                if(inv[i]->query("id") == "nightingale"){
                        destruct(inv[i]);
                        j++;
                }
        }       
        if (j) {        
           message_vision("��������������У�ҹݺ���̵������·�ȥ��\n", me);
                set("bird_flee", 1);
                call_out("bird_back", 10);
                return 1;
        }  
        return 1;
} 
void bird_back(){
        message_vision("�����ֳ������ö���������\n", this_object());
        delete("bird_flee");
} 
void reset(){
        ::reset();
        set("tree", 1);
}
