// by xgchen
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIR"飞燕神剑"NOR, ({ "feiyan","sword" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                 set("value", 100000 );
               set("unit", "把");
                set("sxwuqi", 1);
            set("long", "一把红色宝剑,剑身刻有:飞燕两个字。\n");
                set("wield_msg", HIR"$N「唰」地一声从背后的剑鞘抽出一把$n。\n"NOR);
                set("unwield_msg", HIY"$N将手中的$n"HIB"插入背后的剑鞘。\n"NOR);
                set("armor_prop/armor", 5);
                set("armor_prop/spells", 5);
        }
      init_sword(120);
           setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("force");
        victim->receive_damage("sen",dam/5);
	victim->receive_damage("kee",1,me);
        return HIR "飞燕剑卷起的剑气发出红光,$n心神不定,头昏眼花了。\n" NOR;
}
void init()
{
  if(this_player()==environment())
  add_action("do_combine","duan");
}

int do_combine()
{
int i,sp=0,il=0;
object commcase,me, *inv;
object feiyan;
me = this_player();
inv = all_inventory(me);
i=0;
while(i<sizeof(inv))
                {
                        if(base_name(inv[i]) == "/d/yihua/npc/obj/feiyan1") {sp = 1; feiyan = inv[i];}
                        i++;
                }
         if(me->query("family/master_name")=="燕南天") {il = 1;}
if(sp && il )
{
        message_vision(HIR"$N摧动灵神决的真气把手中的飞燕神剑断裂。\n\n飞燕神剑因此断开一半。\n"NOR,me);
 me->set_skill("feiyan-sword",1);
 destruct(feiyan);
}
else 
message_vision(HIR"$N灵神决的功力不够，险些被剑所伤!\n"NOR,this_player());

return 1;
}

