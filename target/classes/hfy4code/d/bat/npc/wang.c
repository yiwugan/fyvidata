 // wang.c
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("������", ({ "wang tian shou" }) );
    set("title", HIR "��������" NOR);
    set("gender", "����" );
    set("age", 55);
    set("str", 50);
    set("long",
        "
�����˵�һ˫���ֻ����ݣ������ľ�����ǻ���ӥצ�ŵĵ�һ���֡���ʮ 
��ǰ�ѽ�����֮λ����������ֶ����ά�ܣ��������Ѻ����ڽ����߶��� 
\n"
        );
    set("chat_chance", 1);
    set("chat_msg", ({
        "��������Ϊ���صĵ�������֪��֪���½��������ֳ��˸����µ����\n",
            }) );
    set("attitude", "friendly");
    set_skill("unarmed", 200);
    set_skill("move", 80);
    set_skill("dodge",100);
    set_skill("parry",100);
    set_skill("five-steps",100);
    map_skill("unarmed", "shuaibei");
    map_skill("dodge","five-steps");
    set("combat_exp", 1000000);
    set("inquiry", ([ "out":"go out",
                    "out":"go out" ]));
    setup();
    carry_object("/obj/armor/cloth")->wear();
    carry_object(__DIR__"obj/mengui");
}       
