 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("��ʤ����", ({ "master yue", "master" }) );
        set("nickname", HIY"���"HIW"����"NOR);
        set("gender", "����" );
        set("class","official");
        set("age", 44);
        set("str", 50);
        set("cor", 60);
        set("cps", 30);
        set("int", 30);
        set("per", 40);
        set("attitude","friendly");
        set("max_force", 5000);
        set("force", 5000);
        set("force_factor", 150);
        set("rank_nogen",1); 
        create_family("��͢����", 5, "��������");  
        set("title", "ŭ�����");              
        set("long",
"
�㿴�ſ��ţ�������λ���������ǵ���ͳ��ʮ��ֱ��������׳־δ������ɣ�
\n"
        );
        set("combat_exp", 8000000);
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);
        set("agi",25);
        set("int",30);
        
        set_skill("move", 180);
        set_skill("spear", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("yue-spear",180);
        set_skill("manjianghong",180);
        set_skill("literate", 150);
        set_skill("puti-steps",180);
        set_skill("unarmed",220);
        set_skill("leadership",250);
        set_skill("strategy",250);
        set_skill("changquan",300);
        
        map_skill("unarmed","changquan");
        map_skill("dodge","puti-steps");
        map_skill("force", "manjianghong");
        map_skill("spear","yue-spear");
        map_skill("parry","yue-spear");  
        set_temp("apply/attack",200);
        set_temp("apply/dodge", 200);
        set_temp("apply/parry", 200);
        set("marks/�ٸ�/����",  1);
        set("chat_chance_combat",50);
        
        
        
        setup();
        carry_object(__DIR__"obj/goldarmor")->wear();
        carry_object(__DIR__"obj/silverarmor")->wear();
        carry_object("/obj/weapon/spear")->wield();
}  
int is_ghost() { return 1; } 
/* int recognize_apprentice(object ob)
{
        if( ob->query("marks/����") )
        {
                say("�����ȵ�������޵ľ��������ֲ���֮�ˣ�\n");
                kill_ob(ob);
                ob->kill_ob(this_object());
                return 0;
   }
        if( ob->query("marks/��") )
                return 1;
        return 0;
} */ 
void attempt_apprentice(object ob)
{
        if( ob->query("marks/�ٸ�/����")&&ob->query("class")=="official" ) 
                call_out("do_recruit", 2, ob);
 
}
void do_recruit(object ob)
{
                command("smile");
                command("say ������ǡ����ұ��������ĸ��֡�");
                command("recruit " + ob->query("id") );
                ob->set("class", "official");
                ob->set("vendetta_mark", "authority");
}  
string *cishi= ({
"��","��","��","��","��","��","��","��","��","��","�","ʯ","�","��","��",
"��","Ǭ","��","��","ԭ","��","μ","��","��","��","̩","��","�","��","��","ͨ","��","��",
"��","��","��","��","��","̫ƽ","��","Ԭ","��","��","��","�","Ͽ","��","��","��","��","ȫ",
"��","��","��","��","��","̨","��","��","��","�Ͻ�","͡","��","��","��","��","��","��","��",
"��","��","��","ά","ï","��","��","��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","ʩ","��","��","��","��","��","��","ѭ","��","��","÷","Ӣ","��","��","����",
"��","��","��","��","��","��","��","��","��","��","��","�","��","��","��","��","��","�",
"��","��","����","��","����","��","��","��","��","��"
}); 
string *tuanlian= ({
"��","�","Ϋ","��","��",
"��","��","��","��","��","��","��"
}); 
string *fangyu= ({
"��","��","��","��","��","֣",
"��","��","�","��","۫","��","��","��","��","��","�","��","�","��","��","Ī","��","�",
"��","��","��","ޭ","��","��","ü","��","½","��"
}); 
string *guancha= ({
"��","��","��","��","۩","��","��","��","��","��","��","֣","��","��","��","��","�","��",
"��","��","��","��","��","��","��","��","º","��","��","ͬ","��","ҫ","��","�~","��","ߓ","��","��","μ","��","��","��",
"����","��","Խ","��","��","��","��","��","��","��","��","��","��","®","��","��","��","��","��","��",
"��","��","��","̶","��","��","Ȫ","��","��","��","��","��","��","��","��","��","��","��","ǭ"
}); 
string *jiedu= ({
"̩��","����","����","��","��ƽ","����","���","����","��","��������",
"ɽ�϶���","��ʤ","����","�ѻ�","����","����","�ɵ�","����","�õ�","����","����",
"����","����","�û�","����","����","����","����","����","����","����","����","����",
"����","����","����","����","���","��Զ","�䰲","��","ƽ��","��","����","����",
"����","����","����","����","����","����","ɽ������","����","����","�䶨","����","����",
"�俵","�庣","����","��Զ","����","����","����","����","����","��˳","�ù�","����",
"����","����","���","����","��ͬ"
});
                 
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 1024000 ) {
                student->set("title","��͢���� "+cishi[random(sizeof(cishi))]+"�ݴ�ʷ");
                return ;
        } else if ( exp <= 2048000 ) {
                student->set("title","��͢���� "+tuanlian[random(sizeof(tuanlian))]+"������ʹ");
                return ;
        } else if ( exp <= 3315000 ) {
                student->set("title","��͢���� "+fangyu[random(sizeof(fangyu))]+"�ݷ���ʹ");
                return ;
        } else if ( exp <= 5312000 ) {
                student->set("title","��͢���� "+guancha[random(sizeof(guancha))]+"�ݹ۲�ʹ");
                return ;
        } else if ( exp <= 8800000 ) {
                student->set("title","��͢���� "+jiedu[random(sizeof(jiedu))]+"�ڶȹ۲�����");
                return ;
        } else               
                student->set("title","��͢���� "+jiedu[random(sizeof(jiedu))]+"�ڶ�ʹ");
                return ;
}    
