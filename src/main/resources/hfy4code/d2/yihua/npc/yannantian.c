#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
inherit F_MASTER;
string ask_me();
string ask_app();
void create()
{
        set_name("������", ({ "master yan", "master", "yan" }) );
        set("long",
                "����С�����ʦ����������һ������ȫ������ϣ�������˿��\n");
        set("nickname", HIY"Ѫ�ྪ��"NOR);
        create_family("������",3,"����");
         set("str", 45);
        set("cor", 45);
        set("cps", 45);
        set("agi",45);
        set("int",45);
       set("attitude","friendly");
        set("max_kee", 999999999);
        set("max_sen", 999999999);
        set("max_gin", 999999999);
        set("kee", 20000);
        set("sen", 20000);
        set("gin", 20000);
        set("max_force", 20000);
        set("max_atman", 5000);
set("max_mana", 6000);
set("force", 20000);
        set("force_factor", 700);
                 set("inquiry", ([
"������": "����������ʦ����ӥ���������� \n",
                "����" : (: ask_me :),
                "����" : (: ask_me :),
                "��ʦ" : (: ask_app :),
        ]) );
set("combat_exp", 999999999);
        set_temp("apply/damage",500);
        set_skill("unarmed", 500);
        set_skill("force",500);
        set_skill("parry",500);
         set_skill("dodge",500);
 set_skill("move",500);
            set("chat_chance", 300);
set("chat_msg", ({
                "������˵������Ȼ��ūû�����ͺ��ˣ����һ����Լ���һ�档\n",
                "������˵�������»�û�������������ˣ���һ��Ҫɱ��,Ϊ��ū����\n",
        }) );

    setup();
        carry_object("/obj/cloth")->wear();
}
string ask_app()
{
        object ob;
        if ( (int)this_player()->query("combat_exp") < 3000000 )
                return RANK_D->query_respect(this_player()) + 
                "��ľ���̫ǳ�ˡ�";
        if (this_player()->query("yan_over")!=1)
                return RANK_D->query_respect(this_player()) + 
                "�������㣡";
        if ( (int)this_player()->query("killyaoyue") != 1 )
                return RANK_D->query_respect(this_player()) + 
                "�Բ�����������δ��?";
                command("recruit " + this_player()->query("id") );

        return "�ðɣ��ܲ��ܰ��ұ���Ϳ����С����ˡ�";

}string ask_me()
{
        object ob;
        if ( (int)this_player()->query("combat_exp") < 3000000 )
                return RANK_D->query_respect(this_player()) + 
                "��ľ���̫ǳ�ˡ�";
        if (this_player()->query("yan_over"))
                return RANK_D->query_respect(this_player()) + 
                "��ô�ˣ������⣿";
        if ( (int)this_player()->query("killyaoyue") != 1 )
                return RANK_D->query_respect(this_player()) + 
                "�Բ�����������δ��?";
        ob = new("/d/yihua/npc/obj/xueyan");
        ob->move(this_player());
        this_player()->set("yan_over",1);
            message_vision("$N�õ��˷��ལ��\n",this_player());

        return "�ðɣ��ܲ��ܰ��ұ���Ϳ����С����ˡ�";

}
void attempt_apprentice(object me)
{
        switch(random(4)) {
                case 0:
message_vision("$N��$n�������С����Ϳ����ˣ��ҿ��Ƿ��ˣ�\n", this_object(),me);
                        break;
                case 1:
message_vision("$N��$n��������һ��û�������Ҷ������������ȥ�ɣ��Ҳ���ͽ����\n", this_object(),me);      
                        break;
                case 2:
message_vision("$N��$n������ʲô����������ô�����Ϊʦ��\n", this_object(),me);             
                        break;
                case 3:
message_vision("$N��$n������û��ʲôֵ����ȥѧ�ģ����������ھ�֪���ˣ�\n", this_object(),me);
                        break;
        }
                        return;

}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yanyu");
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 5000000 ) {
                student->set("title","�����Ź��ŵ���");
                return ;
        } else
                student->set("title",HIM"�����ž����콾"NOR);
                return ;
}

