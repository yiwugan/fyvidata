// by xgchen
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIR"������"NOR, ({ "feiyan","sword" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                 set("value", 100000);
                 set("no_sell",1);
               set("unit", "��");
                set("sxwuqi", 1);
            set("long", "һ�Ѻ�ɫ����,�������:���������֡�\n");
                set("wield_msg", HIR"$N��ৡ���һ���ӱ���Ľ��ʳ��һ��$n��\n"NOR);
                set("unwield_msg", HIY"$N�����е�$n"HIB"���뱳��Ľ��ʡ�\n"NOR);
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
        return HIR "���ལ����Ľ����������,$n���񲻶�,ͷ���ۻ��ˡ�\n" NOR;
}
void init()
{
  add_action("do_combine","duan");
}

int do_combine()
{
object commcase,me;
me = this_player();
commcase = new("/d/yihua/npc/obj/feiyan1");
if(me->query("class") == "yanyu" && me->query("force_factor") < 200)
{
        message_vision(HIR"$N�ݶ�����������������еķ����񽣶��ѡ�\n\n��������˶Ͽ�һ�롣\n"NOR,me);
        commcase->move(me);
        destruct(this_object());
              }
else 
message_vision(HIR"$N������������Щ��������!\n"NOR,this_player());

return 1;
}
