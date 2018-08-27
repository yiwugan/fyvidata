inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int give_him();
// int kill_him();
void create()
{
        set_name("������", ({ "hua hegen", "hua"}) );
//        set("nickname", "");
//        set("pursuer", 1);
        set("title","����˾ͽ");
        set("gender", "����" );
        set("age", 46);
        set("agi",30);
        set("str", 22);
        set("per", 28);
        set("int",24);
        set("attitude","friendly");
        set("max_force", 5000);
        set("force", 5000);
        set("force_factor", 40);
        set("max_mana", 5000);
        set("mana", 5000);
        set("max_atman", 5000);
        set("atman", 5000);
        set("long",
"
���Ǹ����꺺�ӣ�Ŀ���ڴ����λ��˾ͽ��\n"
        );
        create_family("����", 12, "����");
        set("chat_chance_combat", 20);
//        set("chat_msg_combat", ({
//                (: perform_action, "blade.liuyunxiyu" :)
//        }) );
        set("combat_exp", 1000000);
        set_skill("dodge", 110);
        set_skill("move",140);
        set_skill("force", 140);
        set_skill("sword", 110);
        set_skill("literate", 120);
        set_skill("unarmed",110);
//      set_skill("tianlong-shengong", 110);
        set_skill("duan-yiyangzhi", 110);
        map_skill("force", "tianlong-shengong");
        map_skill("unarmed", "duan-yiyangzhi");
//        map_skill("parry", "");        
// map_skill("parry","huanyu-blade");
//       map_skill("blade", "huanyu-blade");    
        set("inquiry", ([
                "�軨" : (: give_him :),
                "chahua" : (: give_him :)
        ]));
        setup();
     carry_object(__DIR__"obj/guanfu")->wear();
//  carry_object(__DIR__"obj/long-blade")->wield();

}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N˵����������ʹ�����ҪһЩ�ϵȲ軨��������\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N����$nһ�ۣ��ʵ���������軨����Ȥ�𣿣�����\n",this_object(),ob);
                        break;
        }
}
int give_him()
{
        object me , obj;
        me = this_player();
 
        if(me->query("gongxian") > 1000) 
           {
         message_vision("$N˵������Ĺ�ְ̫��������Ҫ������ô�򵥵����񣡻���ȥ��һЩ���ѵİɡ�\n",this_object(), me);
         return 1;
            }
//      if( !query("given")) {
        obj = new("/questnew/huapen");
        message_vision("$N˵������Ȼ������軨����Ȥ���ҾͰ�������Ҫ�Ĺ������������ˣ�
�����޸���$nһ�����»��衣\n",this_object(), me);
        obj->move(me);
//      set("given",1);
        return 1;
//      }
//      return 0;
}


int accept_object(object who, object ob)
{
  int  exp, pot, gong, score;
  exp = random(100)+10000;
  pot = exp / 5 + 100;
  gong = exp / 50 + 2;
  score = exp / 50 +5;
//   if(!(who->query("class") == "dali") )
// {
//   write("������˵��:�㲻�Ǵ�����ӣ��������������Ķ����Ҳ�Ҫ��\n");
//     return 0;
// 115
//  }
  if(!(ob->query("pname") == who->query("id")) )
    {
     write("������˵��:��軨�������ֳ����ģ��������������Ķ�����û���ˣ�\n");
     return 1;
    }
  if(ob->query("name") == "[1;33m��Ʒ�軨[2;37;0m")
    {
     tell_object(who, "������˵������Ϊ���������˹��ף�����Ӧ�õõ�������\n");
        who->add("combat_exp",exp);
        who->add("potential",pot);
//      who->add("score",score);
        who->add("gongxian",gong);
        tell_object(who,HIW"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+
        chinese_number(gong) + "��Դ�����Ĺ��׵�\n" NOR);
//      chinese_number(score) + "���ۺ����ۡ�\n"
        return 1;
    }
  if(ob->query("name") == "[1;32mһƷ�軨[2;37;0m")
    {
     tell_object(who, "������˵������Ϊ���������˹��ף�����Ӧ�õõ�������\n");
        who->add("combat_exp",exp*3/4);
        who->add("potential",pot*3/4);
//      who->add("score",score*3/4);
        who->add("gongxian",gong*3/4);
        tell_object(who,HIW"�㱻�����ˣ�\n" +
        chinese_number(exp*3/4) + "��ʵս����\n"+
        chinese_number(pot*3/4) + "��Ǳ��\n"+
        chinese_number(gong*3/4) + "��Դ�����Ĺ��׵�\n" NOR);
//        chinese_number(score*3/4) + "���ۺ����ۡ�\n"
        return 1;
    }
  if(ob->query("name") == "[33m��Ʒ�軨[2;37;0m")
    {
     tell_object(who, "������˵������Ϊ���������˹��ף�����Ӧ�õõ�������\n");
//     command("say ��Ϊ���������˹��ף�����Ӧ�õõ�������\n");
        who->add("combat_exp",exp/2);
        who->add("potential",pot/2);
//      who->add("score",score/2);
        who->add("gongxian",gong/2);
        tell_object(who,HIW"�㱻�����ˣ�\n" +
        chinese_number(exp/2) + "��ʵս����\n"+
        chinese_number(pot/2) + "��Ǳ��\n"+
        chinese_number(gong/2) + "��Դ�����Ĺ��׵�\n" NOR);
//        chinese_number(score/2) + "���ۺ����ۡ�\n"
        return 1;
    }
  if(ob->query("name") == "[1;37m��Ʒ�軨[2;37;0m")
    {
     tell_object(who, "������˵������Ϊ���������˹��ף�����Ӧ�õõ�������\n");
//     command("say ��Ϊ���������˹��ף�����Ӧ�õõ�������\n");
        who->add("combat_exp",exp/4);
        who->add("potential",pot/4);
//      who->add("score",score/4);
        who->add("gongxian",gong/4);
        tell_object(who,HIW"�㱻�����ˣ�\n" +
        chinese_number(exp/4) + "��ʵս����\n"+
        chinese_number(pot/4) + "��Ǳ��\n"+
        chinese_number(gong/4) + "��Դ�����Ĺ��׵�\n" NOR);
//        chinese_number(score/4) + "���ۺ����ۡ�\n"
        return 1;
    }
  tell_object(who,"������˵��������ʹ�����Ҫ�����ò軨��\n");
  return 0;
}
