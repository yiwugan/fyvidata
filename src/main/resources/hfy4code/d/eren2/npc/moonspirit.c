#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("����", ({ "moon spirit","spirit" }) );
        set("nickname",HIC"�¹���ˮ"NOR);
        set("title","����ɽׯ   ��С��");
        set("gender", "Ů��");
        set("quality","good");
        set("age",19);
        set("combat_exp", 25300000);
         set("long",
"��ɫˮ���䣬�·��в㵭�����������������·���һ����������Ӱ���ƿ���
���֣��¹�̸������������ǡ�������������ϡ��԰׵Ĺɣ��԰����¡�\n"
        );
        set("max_force",50000);
        set("force",50000);
        set("force_factor",900);
                set("max_gin",33000);
                set("max_sen",33000);
                set("con",40);
                set("int",27);
                set("str",25);
                set("cor",80);
                set("agi",40);
                set("per",100);
        set_skill("move",150);
        set_skill("parry", 300);
        set_skill("blade",300);
        set_skill("dodge",150);
                set_skill("moon-blade",120);
                set_skill("bat-blade",300);
                set_skill("demon-blade",300);
                set_skill("demon-steps",300);           
                set_skill("ittouryu",300);
                set_skill("lianxin-blade",300);
                set_skill("qiusheng-blade",300);
                set_skill("shenji-blade",300);
                set_skill("shenji-steps",300);          
                set_skill("springrain-blade",300);
           set_skill("shortsong-blade",300);
                map_skill("blade","moon-blade");
        map_skill("dodge","moon-blade");
        map_skill("parry","moon-blade"); 
        setup();
        carry_object("/questnpc/obj/yueshencloth")->wear();
        carry_object("/questnpc/obj/yueshenblade")->wield();
        set_temp("shield_force/type","force");
        set_temp("shield_force/ratio",2500);
        set_temp("shield_force/msg",
                CYN"$n���ϵĹ⻪������$N�Ĺ��ơ�\n"NOR);
        set("revival",1);
} 
int do_attack() {
        
        if (query_busy())
                stop_busy();
        if (!query_temp("weapon"))
                carry_object("/questnpc/obj/yueshenblade")->wield();
        
        switch(random(8)) {
                case 1:
                        this_object()->ccommand("enable blade bat-blade");
                        this_object()->set("class","bat");
                        if(!random(4))
                                this_object()->ccommand("perform shiwanshenmo");
                        break;
                case 2:
                        this_object()->ccommand("enable blade demon-blade");
                        this_object()->ccommand("enable dodge demon-steps");                    
                        this_object()->set("class","demon");
                        if(!random(4))
                                this_object()->ccommand("perform tiandirenmo");
                        break;
                case 3:
                        this_object()->ccommand("enable blade ittouryu");
                        this_object()->set("class","ninja");
                        if(!random(4))
                                this_object()->ccommand("perform gobankiri");
                        break;
           case 4:
                        this_object()->ccommand("enable blade lianxin-blade");
                        this_object()->set("class","shaolin");
                        if(!random(4))
                                this_object()->ccommand("perform yipianlianxin");
                        break;
                case 5:
                        this_object()->ccommand("enable blade qiusheng-blade");
                        this_object()->set("class","huangshan");
                        if(!random(4))
                                this_object()->ccommand("perform jingsheng");
                        break;
                case 6:
                        this_object()->ccommand("enable blade shenji-blade");
                        this_object()->ccommand("enable dodge shenji-steps");                           
                        this_object()->set("class","shaolin");
                        if(!random(4))
                                this_object()->ccommand("perform jichulianhuan");
                        break;
                case 7:
                        this_object()->ccommand("enable blade shortsong-blade");
                        this_object()->set("class","legend");
                        if(!random(4))
                                this_object()->ccommand("perform duangechangmeng");
                        break;
                case 0:
                        this_object()->ccommand("enable blade springrain-blade");
                        if(!random(4))
                                this_object()->ccommand("perform dangshimingyue");
                        break;
        }    
}
void heart_beat()
{
        ::heart_beat();
        if(is_fighting())
                do_attack();
}       
