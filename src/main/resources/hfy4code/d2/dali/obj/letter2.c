#include <armor.h>
inherit ITEM;
#include <ansi.h>

void diu()
{
 message_vision("$N向怀里一摸，发现密函已经不见了，哎！！。。。。\n",this_player());
 this_player()->delete_temp("lettertime") ;
 destruct(this_object());
}

void create()
{
        string st11;
        string *order=({"南宫十一郎","南宫十三郎","南宫十四郎","吴青","蓝胡子",
"大胡子","忏悔徒","楚楚","老实和尚","莫不屈","中年书生","蓝天锤","渔夫","文人墨客",
"马老四","珠宝商","冷红儿","中药店老板","武林大豪杰","风四娘","王若钢","人和老人","茅大先生",
"城卫","胭松","班察那"});
        set_name(("密函"), ({ "letter"}) );
        st11=order[random(26)];
        set("toname",st11);
        set("long", HIW"                "+ st11 + HIC"    亲启\n"NOR); 
        set_weight(1000);
        set("value", 10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
        }
//        setup();
        call_out("diu", 800, 1);  
}