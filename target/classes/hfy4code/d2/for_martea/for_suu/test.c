 inherit ITEM;
void create()
{
        set_name("��̦", ({ "lichen" }) );
        set_weight(100); 
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�����ͱ���ÿ�����߱�����һ����̦����ʮ�Ա�ֱ���ϡ�\n");
                set("value", 1);
        }
} 
void init()
{
        
        add_action("do_climb","climb");
}
int do_climb(string arg)
{
        object me;
        
        me=this_player();
        me->set("potential",1000);
        tell_object(me,"pots should be added");
        return 1;
}
         
