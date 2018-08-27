 inherit ITEM;
int assign_weapon(string arg, object me);
int move_weapon(string arg, object me);
void create()
{
    set_name("��ʯ��", ({ "table" , "��ʯ��", "stone table"}) );
    set_weight(8000000);
    set_max_encumbrance(80000);
    set("no_get", 1);
    set("no_shown", 1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("prep", "on");
        set("unit", "��");
        set("long", "һ���޴��ʯ�������������ŵ�������ǹ�����������ޡ�ذ������
�����ĺ��ӣ������ϱ������ƣ��㲻�������������������������裩\n");
    }
    ::init_item();
} 
int is_container() { return 1; } 
void init(){
        add_action("do_touch", "touch");
} 
int do_touch(string arg){
        object me, weapon;
        
        me = this_player();
        if(arg == "blade" || arg == "��" ){
                assign_weapon("blade", me);
        } else if(arg == "sword" || arg == "��" ){
                assign_weapon("sword", me);
        } else if(arg == "spear" || arg == "ǹ"){
                assign_weapon("spear", me);
        } else if(arg == "hammer" || arg == "��" ){
                assign_weapon("hammer", me);
        } else if(arg == "axe" || arg == "��" ){
                assign_weapon("axe", me);
        } else if(arg == "whip" || arg == "��" ){
                assign_weapon("whip", me);
   } else if(arg == "dagger" || arg == "ذ��" ){
                assign_weapon("dagger", me);
        } else {
                return notify_fail("��Ҫ��ʲô��\n");
        }       
        return 1;
} 
int assign_weapon(string arg, object me) {
        object weapon; 
        if(me->query("attribute_mark") == "fire"){
                move_weapon("fire_"+arg, me);
        } else if(me->query("attribute_mark") == "gold"){
                move_weapon("gold_"+arg, me);
        } else if(me->query("attribute_mark") == "wood"){
                move_weapon("wood_"+arg, me);
        } else if(me->query("attribute_mark") == "earth"){
                move_weapon("earth_"+arg, me);
        } else if(me->query("attribute_mark") == "water"){
                move_weapon("water_"+arg, me);
        } else {
                return 0;
        }
        return 1;
} 
int move_weapon(string arg, object me){
        object weapon;
        
        weapon = new(__DIR__+arg);
        if(query("box/"+arg)){
                tell_object(me, "�������Ѿ������ˡ�\n");
                return 1;
        }
        if(objectp(weapon)){
                message_vision("���ӵ�����һ��" + weapon->name() + "��������$N���С�\n", me);
                weapon->move(me);
                set("box/"+arg, 1);
        }
        return 1;               
}    
