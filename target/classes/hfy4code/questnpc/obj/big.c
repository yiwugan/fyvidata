// jin-nang by zzfy
#include <ansi.h>
inherit ITEM;
void create()
{
        string *order=({HIB"蓝色"NOR +HIR"锦囊"NOR, HIY"金色"NOR+HIR"锦囊"NOR,HIW"白色"NOR+HIR"锦囊"NOR,HIM"紫色"NOR+HIR"锦囊"NOR,HIC"青色"NOR+HIY"锦囊"NOR,HIR"红色"NOR +HIY"锦囊"NOR,});
        set_name((order[random(6)]) , ({ "jin-nang", "jin","nang"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                HIY "一个用金丝编成的锦囊，似乎可以(open)打开。\n"NOR);
                set("unit","个");
                set("value", 0);
        }
        }
void init()
{
if( environment() == this_player() )
        add_action("open_gongbao","open");
}
int open_gongbao(string arg)
{
        int exp;
        int pot;
        int sscore;
        if ( arg == "jin-nang"){
        exp =random(3000)+3000;
        pot =random(1400) +800;
        sscore =random(30)+ random(20);
        message_vision(HIM"$N擦了擦额头的汗水，迫不及待地用颤抖的双手打开了锦囊。\n"NOR,this_player());
        this_player()->add("combat_exp",exp);
        this_player()->add("potential",pot); 
        this_player()->add("score",sscore);
        tell_object(this_player(),HIR"哇！！！！你被奖励了：\n\n" +
        chinese_number(exp) + "点实战经验。\n"+
        chinese_number(pot) + "点潜能。\n" +
        chinese_number(sscore) + "点综合评价。请继续努力！！！\n"NOR);
        destruct(this_object());
        return 1;
     }
     return 0; 
}
