#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("��è��", ({ "xiong maoer","maoer" }) );
        set("gender", "����" );
        set("title", HIR"������һ������"NOR );
        set("long",
        "ֻ���������˳ߣ���ü���ۣ�����б���ű����ʶ̵�����������\nֻ�����ľƺ�«��һ��߸裬һ��ʹ����\n"
                );
        set("attitude", "peaceful");
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
                      (:perform_action,"blade.jichulianhuan":),
                      (:perform_action,"dodge.shenjimiaosuan":),
        }));
        set("age", 25);
        set("cps", 40);
        set("int", 50);
        set("per", 40);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 800000);
        set("force", 1000);
        set("max_force", 1000);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 30); 
        set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "��è�������߸裺ǧ����������飬�����ԹŶ�Ӣ�ۣ��ҰѺ��г���ƣ�Ƽˮ����һЦ�ꡣ\n",
        "��è���������������˰����ˣ��㵽���������\n",
                }) );
        set("inquiry",  ([
                "����" : "�������˰����ˣ����Ƿ񻹻����˼䣿\n",
                "������" : "�������֪����Ѿͷ����Ϣô������������ô��\n",
                "������" : "�������ô����������ħ�ǣ���\n",
                "�����" : "����������˾���˭��Ц������أ�\n",
                ])); 
        set_skill("unarmed", 100);
        set_skill("blade", 100);
        set_skill("shenji-blade", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("move", 100);
        set_skill("shenji-steps", 100);
        set_skill("dragonstrike",120);
        
        map_skill("unarmed","dragonstrike");
        map_skill("dodge", "shenji-steps");
        map_skill("blade", "shenji-blade");
        map_skill("parry", "shenji-blade");
                
        setup();
        carry_object("/d/loulan/obj/blade")->wield();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/d/loulan/obj/winepot");
}       
