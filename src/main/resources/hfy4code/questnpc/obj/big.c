// jin-nang by zzfy
#include <ansi.h>
inherit ITEM;
void create()
{
        string *order=({HIB"��ɫ"NOR +HIR"����"NOR, HIY"��ɫ"NOR+HIR"����"NOR,HIW"��ɫ"NOR+HIR"����"NOR,HIM"��ɫ"NOR+HIR"����"NOR,HIC"��ɫ"NOR+HIY"����"NOR,HIR"��ɫ"NOR +HIY"����"NOR,});
        set_name((order[random(6)]) , ({ "jin-nang", "jin","nang"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                HIY "һ���ý�˿��ɵĽ��ң��ƺ�����(open)�򿪡�\n"NOR);
                set("unit","��");
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
        message_vision(HIM"$N���˲���ͷ�ĺ�ˮ���Ȳ��������ò�����˫�ִ��˽��ҡ�\n"NOR,this_player());
        this_player()->add("combat_exp",exp);
        this_player()->add("potential",pot); 
        this_player()->add("score",sscore);
        tell_object(this_player(),HIR"�ۣ��������㱻�����ˣ�\n\n" +
        chinese_number(exp) + "��ʵս���顣\n"+
        chinese_number(pot) + "��Ǳ�ܡ�\n" +
        chinese_number(sscore) + "���ۺ����ۡ������Ŭ��������\n"NOR);
        destruct(this_object());
        return 1;
     }
     return 0; 
}
