 // Room: waterpath.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "寒云瀑"); 
        set("long", @LONG
一道瀑布从涧顶急泻而下，飞珠溅玉，轰响震耳。瀑布下方聚成一个水潭。潭
水微蓝，虽然与鸣响的瀑布只在咫尺，却有一种端庄的秀丽与宁静。盈盈蓝水，微
微波动，有说不出的明澄清澈，可爱得让人忘却了潭水的寒冷，忍不住想下去游泳。
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
                return notify_fail("还是先宰了水龙在游吧。\n");
        }
        if(me->is_busy() || me->is_fight()){
                return notify_fail("你正在忙。\n");
        }
        if (me->query("attribute/mark") == "fire" && me->query_temp("attribute") != "water"){
                message_vision("寒冷的潭水让$N感到一阵痛楚，$N迅速离开潭水。\n", me);   
                return 1;
        }
        message_vision("$N跃入潭内，冰冷的潭水让$N精神陡然一震。\n", me);
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
                message_vision("$N的精气神全恢复了！！\n", me);
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
