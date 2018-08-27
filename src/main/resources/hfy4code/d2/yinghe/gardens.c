 // FYWorkshop
inherit ROOM;
void bird_attack(object me);
int bird_flee(object me);
void create()
{
        set("short", "��ľ��ݺ԰");
        set("long", @LONG
���Ǻ�ɫ�����磬��Ƭ��ľ�л㼯���κ����������ĺ�ɫ--��졢�ۺ졢
ǳ�졢��졢�Ϻ졢糺졣���ļ���ɢ�����������ﶼȾ�ϵĵ����ĺ�ɫ��Ψһ
��������͸����ɫ���ҶƬ������ɫ�����ɡ�
LONG); 
        //{{ --- by MapMaker 
        set("exits",([
                "northup" : __DIR__"garden",
        ]) );
        set("item_desc", ([
                "tree" : "һ�ÿ���ڴ�С������������𡡣����壩\n", 
                "����" : "һ�ÿ���ڴ�С������������𡡣����壩\n", 
        ]));    
         
        set("tree", 1);
        set("indoors", "linghe");
        setup();
} 
void init(){
        add_action("do_chop", "chop");
} 
int do_chop(string arg){
    object obj;
    object me;
    
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
                ob=new(__DIR__"obj/tree2");
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
