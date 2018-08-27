#include <ansi.h>
#include <command.h>
#include <condition.h>
#define NPC_D  "/d/eren2/temp/npclist" 
inherit __DIR__"smart_npc";
//inherit NPC; 
void auto_npc_setup(string name, int basic, int special, int auto_weapon, string weapon_dir, string char_type, string my_char);  
void create()
{ 
        set_name("����",({"fighter"}));
        set("title",YEL"������ʮ����"NOR);
        set("long", "����̽��¥�������ÿ��˵Ļ���һ��������ɵվ�ű���ɱ��\n");
        set("age",30+random(20));
        set("combat_exp", 6500000);
        
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",100); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("no_fly",1);
        
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",40);
        
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
// set("zombie-killer",1);
        set("officer-killer",1);
        set("dungeon_npc","check");
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
//      CHAR_D->setup_char(this_object());
//      auto_npc_setup("fighter",300,200,0,"/obj/weapon/","magician","necromancy");
        setup();
        carry_object("/obj/armor/cloth")->wear();
}   
void auto_npc_setup(string name, int basic, int special, int auto_weapon, string weapon_dir, string char_type, string my_char) {
        
        string *basic_skill= ({"move","dodge","parry","unarmed","blade","sword",
        "staff","axe","spells","magic","spear","throwing","hammer","whip","force",
        "perception","iron-cloth","cursism","scratching",}); 
        string *pfm_setup = ({"perform_weapon_attack","perform_weapon_attack2","perform_weapon_attack3",
                "perform_weapon_attack4","perform_unarmed_attack4",
                "perform_unarmed_attack","perform_unarmed_attack2","perform_unarmed_attack3",
                "perform_busy_d","perform_busy_u","perform_busy_w"});
        
        string *base_skill_setup = ({"skill_type_w","skill_type_u","skill_type_d",});
        
        string *other_skills = ({"others1","others2","others3","others4","others5","others6"});
        string *temp_setup = ({"set_temp1","set_temp2","set_temp3","set_temp4"});       
        string *mark_setup = ({"set_1","set_2","set_3","set_4"});       
        
        int i, total, x;
        mapping npc;
        string myclass,type,skill,pfm,weapon;
        
        npc=NPC_D->query_npc(char_type,my_char,special);
        set("class",npc["class"]);
        set("gender",npc["gender"]?npc["gender"]:"����");
        set("npc",npc["npc"]);
        set("myname",npc["name"]);
        
// setting up all skills
        for (i=1;i<sizeof(basic_skill);i++){
                set_skill(basic_skill[i],basic);
                if (npc[basic_skill[i]]) {
                        set_skill(npc[basic_skill[i]],special);
                        map_skill(basic_skill[i],npc[basic_skill[i]]);
                }
        }
        set_skill("anxiang-steps", special);
        map_skill("move","anxiang-steps");
        if (!query_skill_mapped("iron-cloth"))
                delete_skill("iron-cloth");
        if (query_skill_mapped("iron-cloth")=="xisui")
                set_skill("xisui",query_skill("xisui",1)/2);
        
//      setting up defense skill.. will only use one of them.
        set_skill("lingxi-zhi",special);
        set_skill("yue-strike",special);
        set_skill("xiaohun-sword",special);
        set_skill("xiaohun-whip",special); 
//      setting up all pfm messages. also setting up secondary pfm skills if necessary
        for (i=0;i<sizeof(pfm_setup);i++){
                if (npc[pfm_setup[i]])
                if (sscanf(npc[pfm_setup[i]],"%s/%s/%s/%s",myclass,type,skill,pfm)==4)
                        set_skill(type,special);
                        set(pfm_setup[i],npc[pfm_setup[i]]);
        } 
//      setting up the basic enable skill set that NPC uses after switching skills.
        for (i=0;i<sizeof(base_skill_setup);i++){
                if (npc[base_skill_setup[i]])
                        set(base_skill_setup[i],npc[base_skill_setup[i]]);
        } 
//      setting up some suplementary skill such as chess,lamasism,...
        for (i=0;i<sizeof(other_skills);i++){
                if (npc[other_skills[i]])
                        set_skill(npc[other_skills[i]],special);
                else break;
        } 
//      the main weapon/unarmed/dodge skill level needs to be adjusted due to coff difference.
        if (npc["skill_type_w"] && npc["w_adjust"]) {
           sscanf(npc["skill_type_w"],"%s/%s",type,skill);
                set_skill(skill,(100+npc["w_adjust"])*query_skill(skill,1)/100);
        }
        if (npc["u_adjust"] && npc["skill_type_u"]) 
                set_skill(npc["skill_type_u"],(100+npc["u_adjust"])*query_skill(npc["skill_type_u"],1)/100);
        if (npc["d_adjust"] && npc["skill_type_d"]) 
                set_skill(npc["skill_type_d"],(100+npc["d_adjust"])*query_skill(npc["skill_type_d"],1)/100);
                
//      setting up temp for chill/juqi
        for (i=0;i<sizeof(temp_setup);i++){
                if (npc[temp_setup[i]])
                        set_temp(npc[temp_setup[i]],special*2+random(special));
                if (npc[mark_setup[i]])
                        set(npc[mark_setup[i]],1);
        } 
//      setting up weapons
        if (auto_weapon && npc["skill_type_w"])
        if (sscanf(npc["skill_type_w"],"%s/%s",weapon,skill)==2) 
                carry_object(weapon_dir+weapon)->wield(); 
}  
