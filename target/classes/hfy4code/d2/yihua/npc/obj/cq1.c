//mouse@wenxin
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIR "百" + HIG "花" + HIC "剑" NOR, ({ "baihua sword", "sword"}) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long",
                        
"一把闪着奇异光芒的锋利宝剑。\n"
);
                set("value", 18000);
                set("for_bandit",1);
                set("material", "steel");
                set("wield_msg", "$N从镶满五色宝石的翡翠剑鞘中抽出一柄寒气逼人的$n。\n");
                set("unwield_msg", "$N随手中将$n抛向空中，$n化作片片飞花落入翡翠剑鞘中。\n");
        }
        ::init_sword(80);
        }
