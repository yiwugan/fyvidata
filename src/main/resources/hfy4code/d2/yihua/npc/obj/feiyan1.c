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
                 set("value", 100000 );
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
         if(me->query("family/master_name")=="������") {il = 1;}
if(sp && il )
{
        message_vision(HIR"$N�ݶ�����������������еķ����񽣶��ѡ�\n\n��������˶Ͽ�һ�롣\n"NOR,me);
 me->set_skill("feiyan-sword",1);
 destruct(feiyan);
}
else 
message_vision(HIR"$N������Ĺ�����������Щ��������!\n"NOR,this_player());

return 1;
}

