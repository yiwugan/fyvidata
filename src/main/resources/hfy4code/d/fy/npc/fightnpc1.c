#include <ansi.h>
inherit NPC;
void auto_smart_fight();
void ask_help();
void auto_npc_setup(string name, int basic, int special, int self_weapon, string weapon_dir, string char_type, string my_char); 
void create()
{ 
        set("age",10+random(10)); 
        set("combat_exp", 1000000);
        set("dungeon_npc","test");
                
        set("max_atman", 500);
        set("atman", 500);
        set("max_mana", 500);
        set("mana", 500);
        set("max_force",800);
        set("force",800);
        set("force_factor",60);
        set("no_fly",1);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",150,140,1,"/obj/weapon/","all","all");
        setup();
        set_name("С��",({"fighter"}));
        set("title",YEL"̽��¥"NOR);
        set("long", "����̽��¥�������ÿ��˵Ļ���\n");
        carry_object("/obj/armor/cloth")->wear();
        set("str",30);
        set("force_factor",90);
} 
void auto_npc_setup(string name, int basic, int special, int auto_weapon, string weapon_dir, string char_type, string my_char) {
        
//      name ---  char name, used in random NPC generator so they have same name.
//      basic --- basic skill level (move,spells,magic,...)     
//      special --- special skill level (diesword,shenji-blade,anxiang-steps,...)
//      auto-weapon --- 0: Do not define weapon; 1: auto define a weapon using sword, blade ....
//      weapon_dir ---- when auto define weapon, the directory of weapon obj located, for exampe, "/d/fy/"
//      char_type ---- fighter_weapon,fighter_unarmed,healer,ironman,magician,zombie-wiper,
//              if you call smart_fight() in chat_chance, NPC will react according to this setting.
//              healer: heal friend in fight, ironman: have iron-cloth
//              magician: using sanqing skills.
//              char_num:
//      my_char ---- this lets you define exactly the type of NPC you want, check string *type for the correct name. 
        string *basic_skill= ({"move","dodge","parry","unarmed","blade","sword",
        "staff","axe","spells","magic","spear","throwing","hammer","whip","force",
        "perception"}); 
        string *type_fighter_w= ({
        "shenji", "bat-blade", "lefthand", "diesword","shortsong",
        "dagou-stick","yue-spear","taiji-sword","sharen-sword","longfenghuan",
        "cloudstaff","doomsword","tanzhi-shentong","qingfeng-sword","liuquan-steps",
        "qiusheng-blade","xuezhan-spear","xuanyuan-axe1","xuanyuan-axe2","softsword",
        "ittouryu","ass-hammer","pangu-hammer","thunderwhip","xinyue-dagger","feixian",         
        "xuezhan-spear2","nine-moon-sword",
        });
        string *type_fighter_u = ({"dragonstrike","doomstrike","taiji","hanshan-strike",
                "yiyangzhi","enmeiryu","tenderzhi","wolf-strike","bazhentu","wolf-claw",
                "nine-moon-claw","lingxi-zhi","yue-strike","luoriquan","shadowsteps",
                "yizhichan","mukuha","yaozhan",
                });
        string *type_healer =({});
        string *type_magician = ({"sq-male","sq-male2","sq-female","dz-an","sq-female2",});
        string *type_ironman= ({"jin-gang","sl-hammer","sl-axe","sl-spear","sl-staff",
                        "sl-yijinjing",});
        
        int i, total, x;
        
        string random_choose;
        int size_w,size_u,size_i,size_m; 
        size_w=sizeof(type_fighter_w);
   size_u=sizeof(type_fighter_u);
        size_i=sizeof(type_ironman);
        size_m=sizeof(type_magician); 
        for (i=1;i<sizeof(basic_skill);i++){
                set_skill(basic_skill[i],basic);
                }
        
        set_skill("anxiang-steps", special);
        map_skill("move","anxiang-steps");
        
        if (my_char == "all")
                switch (char_type) {
                        case "fighter_w": random_choose= type_fighter_w[random(size_w)];
                                                break;
                        case "fighter_u": random_choose= type_fighter_u[random(size_u)];                
                                                break;
                        case "ironman":  random_choose= type_ironman[random(size_i)];
                                                break;
                        case "all":     total=size_w+size_u+size_i+size_m;
                                        x= random(total);
                                        if (x>size_u+size_i+size_m) {
                                                random_choose= type_fighter_w[random(size_w)];
                                                char_type="fighter_w";
                                                }
                                                else if (x>size_u+size_m)       {
                                                        random_choose=type_ironman[random(size_i)];
                                                        char_type="ironman";
                                                        }
                                                else if (x>size_u) {
                                                        random_choose=type_magician[random(size_m)];
                                                        char_type="magician";
                                                        }
                                                else {
                                                        random_choose= type_fighter_u[random(size_u)];
                                                        char_type="fighter_u";
                                                        }                                       
                        default:        break;
                        }                       
        
        if (my_char != "all")  random_choose= my_char;
                
        
        if (!random(5)) set("zombie-killer",1);
        
        if ((!random(10)&& char_type=="all") || char_type=="healer") {
                set("npc_type","healer");
                set("class","bonze");
                set_name("���ֻش�",({name}));
                set_skill("cloudstaff",special);
                set_skill("essencemagic",200);
                set_skill("notracesnow",special+20);
                set_skill("dabei-strike",special+20);
                set_skill("lotusforce",200);
                map_skill("magic","essencemagic");
                map_skill("force","lotusforce");
                map_skill("unarmed","dabei-strike");
                map_skill("staff","cloudstaff");
                map_skill("parry","cloudstaff");
                map_skill("dodge","notracesnow");
                set("perform_attack","staff.longxianyuye");
                set("perform_attack_2","unarmed.qianshouqianbian");     
                if (auto_weapon) carry_object(weapon_dir+"staff")->wield();
                return;
        }
        
        
if (char_type=="fighter_w") {           
        set("npc_type","fighter_w");
        switch (random_choose) {        
// below are fighter_w types.
                case "feixian":  
                                set_name("����",({name}));
                                set_skill("feixian-sword",special+50);
                                set_skill("feixian-steps",special);
                                set_skill("lingxi-zhi",special);
                                map_skill("unarmed","lingxi-zhi");
                                map_skill("sword","feixian-sword");
                           map_skill("parry","feixian-sword");
                                map_skill("dodge","feixian-steps");
                                set("perform_attack","dodge.tianwaifeixian");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break; 
                case "shenji":   
                                set_name("������",({name}));
                                set_skill("shenji-blade",special);
                                set_skill("shenji-steps",special);
                                set_skill("luoriquan",special+50);
                                map_skill("unarmed","luoriquan");
                                map_skill("blade","shenji-blade");
                                map_skill("parry","shenji-blade");
                                map_skill("dodge","shenji-steps");
                                set("perform_attack","blade.jichulianhuan");
                                set("perform_attack_2","unarmed.luori");
                                set("perform_busy","dodge.shenjimiaosuan");
                                if (auto_weapon) carry_object(weapon_dir+"blade")->wield();
                                break;
                case "bat-blade": 
                                set("class","bat");
                                set_name("��������",({name}));
                                set_skill("bat-blade",special-20);
                                set_skill("meng-steps",special);
                                set_skill("luoriquan",special+50);
                                map_skill("unarmed","luoriquan");
                                map_skill("blade","bat-blade");
                                map_skill("parry","bat-blade");
                                map_skill("dodge","meng-steps");
                                set("perform_attack","blade.shiwanshenmo");
                                set("perform_attack_2","unarmed.luori");
                                set("perform_busy","dodge.huanyinqianchong");
                                if (auto_weapon) carry_object(weapon_dir+"blade")->wield();
                                break;
                case "lefthand": 
                                set("class","assassin");
                                set_name("����",({name}));
                                set_skill("lefthand-sword",special+20);
                                set_skill("jinhong-steps",special+50);
                        set_skill("flame-strike",special+20);
                                map_skill("unarmed","flame-strike");
                                map_skill("sword","lefthand-sword");
                                map_skill("parry","lefthand-sword");
                                map_skill("dodge","jinhong-steps");
                                set("perform_attack","sword.duxin");
                                set("perform_busy","dodge.canglongzhaxian");    
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "diesword": 
                                set_name("������",({name}));
                                set("class","legend");
                                set("gender","Ů��");
                                set_skill("diesword",special-20);
                                set_skill("fall-steps",special+50);
                                set_skill("qidaoforce",special);
                                set_skill("meihua-shou",special+50);
                                map_skill("unarmed","meihua-shou");
                                map_skill("sword","diesword");
                                map_skill("parry","diesword");
                                map_skill("dodge","fall-steps");
                                set("perform_attack","sword.caidiekuangwu");
                                set("perform_busy","dodge.luoyeqiufeng");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "shortsong": 
                                set_name("��Ҷ",({name}));
                                set("class","legend");
                                set_skill("shortsong-blade",special-10);
                                set_skill("fall-steps",special+50);
                                set_skill("qidaoforce",special+50);
                                set_skill("meihua-shou",special+50);
                                map_skill("unarmed","meihua-shou");
                                map_skill("blade","shortsong-blade");
                                map_skill("parry","shortsong-blade");
                                map_skill("dodge","fall-steps");
                                set("perform_attack","blade.duangechangmeng");
                                set("perform_busy","dodge.luoyeqiufeng");
                                if (auto_weapon) carry_object(weapon_dir+"blade")->wield();
                           break;
                case "dagou-stick": 
                                set_name("�����޹�",({name}));
                                set("class","beggar");
                                set_skill("dragonstrike",special+20);
                                set_skill("doggiesteps",special+80);
                                set_skill("dagou-stick",special);
                                map_skill("staff","dagou-stick");
                                map_skill("parry","dagou-stick");
                                map_skill("unarmed","dragonstrike");
                                map_skill("dodge","doggiesteps");
                                set("perform_attack","staff.tianxiawugou");
                                set("perform_attack_2","unarmed.xianglongwuhui");
                                if (auto_weapon) carry_object(weapon_dir+"staff")->wield();
                                break;
                case "yue-spear": 
                                set_name("����",({name}));
                                set("class","official");
                                set("marks/�ٸ�/����",1);
                                set_skill("changquan",300);
                                set_skill("puti-steps",special+80);
                                set_skill("yue-spear",special);
                                set_skill("manjianghong",special);
                                map_skill("force","manjianghong");
                                map_skill("spear","yue-spear");
                                map_skill("parry","yue-spear");
                                map_skill("unarmed","changquan");
                                map_skill("dodge","puti-steps");
                                set("perform_attack","spear.zonghengtianxia");
                                set("perform_attack_2","unarmed.yuhuan");
                                if (auto_weapon) carry_object(weapon_dir+"spear")->wield();
                                break;
                case "taiji-sword": 
                                set_name("�������",({name}));
                                set("class","wudang");
                                set_skill("taiji",special);
                                set_skill("five-steps",special);
                                set_skill("taiji-sword",special+50);
                                set_skill("taijiforce",200);
                           map_skill("force","taijiforce");
                                map_skill("sword","taiji-sword");
                                map_skill("unarmed","taiji");
                                map_skill("dodge","five-steps");
                                set("perform_attack","sword.chanzijue");
                                set("perform_attack_2","nianzijue");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "sharen-sword": 
                                set("class","assassin");
                                set_name("ɱ������",({name}));
                                set_skill("lefthand-sword",special+20);
                                set_skill("sharen-sword",special+20);
                                set_skill("jinhong-steps",special+50);
                                set_skill("flame-strike",special+20);
                                map_skill("unarmed","flame-strike");
                                map_skill("sword","sharen-sword");
                                map_skill("parry","lefthand-sword");
                                map_skill("dodge","jinhong-steps");
                                set("perform_attack","sword.sharenruma");
                                set("perform_busy","dodge.canglongzhaxian");    
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "nine-moon-sword": 
                                set("class","shenshui");
                                set("gender","Ů��");
                                set_name("����",({name}));
                                set_temp("nine-moon-force_poison",special*2);
                                set_skill("nine-moon-claw",special);
                                set_skill("nine-moon-sword",special);
                                set_skill("nine-moon-steps",special);
                                set_skill("nine-moon-force",200);
                                map_skill("force","nine-moon-force");
                                map_skill("sword","nine-moon-sword");
                                map_skill("unarmed","nine-moon-claw");
                                map_skill("dodge","nine-moon-steps");
                                map_skill("parry","nine-moon-sword");
                                set("perform_attack","sword.shuanglengcanxia");
                                set("perform_busy","dodge.lianhuanbu");
                           if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "longfenghuan": 
                                set("class","assassin");
                                set_name("˫����",({name}));
                                set_skill("longfenghuan",special);
                                set_skill("jinhong-steps",special+50);
                                set_skill("flame-strike",special+20);
                                map_skill("unarmed","flame-strike");
                                map_skill("hammer","longfenghuan");
                                map_skill("parry","longfenghuan");
                                map_skill("dodge","jinhong-steps");
                                set("perform_attack","hammer.longfengshuangfei");
                                set("perform_busy","dodge.canglongzhaxian");    
                                if (auto_weapon) carry_object(weapon_dir+"hammer")->wield();
                                break;
                case "cloudstaff": 
                                set("class","bonze");
                                set_name("����д��",({name}));
                                set_skill("cloudstaff",special);
                                set_skill("notracesnow",special+20);
                                set_skill("dabei-strike",special+20);
                                map_skill("unarmed","dabei-strike");
                                map_skill("staff","cloudstaff");
                                map_skill("parry","cloudstaff");
                                map_skill("dodge","notracesnow");
                                set("perform_attack","staff.longxianyuye");
                                set("perform_attack_2","unarmed.qianshouqianbian");     
                                if (auto_weapon) carry_object(weapon_dir+"staff")->wield();
                                break;
                case "doomsword": 
                                set("class","fighter");
                                set_name("����һ��",({name}));
                                set_skill("doomsword",special-50);
                                set_skill("doomstrike",special);
                                set_skill("doomsteps",special);
                                map_skill("unarmed","doomstrike");
                                map_skill("sword","doomsword");
                                map_skill("parry","doomsword");
                           map_skill("dodge","doomsteps");
                                set("perform_attack","sword.hunranyijian");
                                set("perform_attack_2","unarmed.hantian");      
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "xuezhan-spear":   
                                set_name("Ѫǹ",({name}));
                                set("class","fugui");
                                set_skill("xuezhan-spear",special);
                                set_skill("hawk-steps",special);
                                set_skill("eagle-claw",special+30);
                                set_skill("skyforce",200);
                                set_skill("iron-cloth",special-50);
                                set_skill("henglian",special-50);
                                map_skill("iron-cloth","henglian");
                                map_skill("force","skyforce");
                                map_skill("unarmed","eagle-claw");
                                map_skill("spear","xuezhan-spear");
                                map_skill("parry","xuezhan-spear");
                                map_skill("dodge","hawk-steps");
                                set("perform_attack","spear.bafangfengyu");
                                set("perform_busy","dodge.yingjichangkong");
                                if (auto_weapon) carry_object(weapon_dir+"spear")->wield();
                                break;
                case "xuezhan-spear2":  
                                set_name("��Ѫǹ",({name}));
                                set("class","fugui");
                                set_skill("xuezhan-spear",special);
                                set_skill("hawk-steps",special);
                                set_skill("eagle-claw",special+30);
                                set_skill("skyforce",200);
                                set_skill("iron-cloth",special-50);
                                set_skill("henglian",special-50);
                                map_skill("iron-cloth","henglian");
                                map_skill("force","skyforce");
                                map_skill("unarmed","eagle-claw");
                                map_skill("spear","xuezhan-spear");
                                map_skill("parry","xuezhan-spear");
                                map_skill("dodge","hawk-steps");
                          set("perform_attack","spear.yutianbigao");
                                set("perform_busy","dodge.yingjichangkong");
                                if (auto_weapon) carry_object(weapon_dir+"spear")->wield();
                                break;
                case "liuquan-steps":   
                                set_name("��Ȫ",({name}));
                                set("class","huangshan");
                                set("gender","Ů��");
                                set_skill("siqi-sword",special);
                                set_skill("liuquan-steps",special);
                                set_skill("yunwu-strike",special);
                                set_skill("xianjing",200);
                                map_skill("force","xianjing");
                                map_skill("unarmed","yunwu-strike");
                                map_skill("sword","siqi-sword");
                                map_skill("parry","siqi-sword");
                                map_skill("dodge","liuquan-steps");
                                set("perform_busy","dodge.liushuichanchan");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "qiusheng-blade":  
                                set_name("����",({name}));
                                set("class","huangshan");
                                set("gender","����");
                                set_skill("qiusheng-blade",special);
                                set_skill("liuquan-steps",special);
                                set_skill("yunwu-strike",special);
                                set_skill("xianjing",200);
                                map_skill("force","xianjing");
                                map_skill("unarmed","yunwu-strike");
                                map_skill("sword","qiusheng-blade");
                                map_skill("parry","qiusheng-blade");
                                map_skill("dodge","liuquan-steps");
                                set("perform_busy","dodge.liushuichanchan");
                                if (auto_weapon) carry_object(weapon_dir+"blade")->wield();
                                break;
                case "qingfeng-sword":  
                                set_name("���",({name}));
                                set("class","huashan");
                           set("gender","Ů��");
                                set_skill("qingfeng-sword",special+20);
                                set_skill("cloud-dance",special);
                                set_skill("zhaixin-claw",special);
                                set_skill("hanmei-force",200);
                                set_skill("iron-cloth",special-50);
                                set_skill("spring-water",special-50);
                                map_skill("iron-cloth","spring-water");
                                map_skill("force","hanmei-force");
                                map_skill("unarmed","zhaixin-claw");
                                map_skill("sword","qingfeng-sword");
                                map_skill("parry","qingfeng-sword");
                                map_skill("dodge","cloud-dance");
                                set("perform_busy","dodge.yexuechuji");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "tanzhi-shentong": 
                                set_name("ǧ�ֹ���",({name}));
                                set("class","huashan");
                                set("gender","Ů��");
                                set_skill("tanzhi-shentong",special);
                                set_skill("anxiang-steps",special);
                                set_skill("zhaixin-claw",special);
                                set_skill("hanmei-force",200);
                                set_skill("iron-cloth",special-50);
                                set_skill("spring-water",special-50);
                                map_skill("iron-cloth","spring-water");
                                map_skill("force","hanmei-force");
                                map_skill("unarmed","zhaixin-claw");
                                map_skill("throwing","tanzhi-shentong");
                                map_skill("dodge","anxiang-steps");
                                set("perform_attack","throwing.mantianhuayu");
                                set("perform_busy","throwing.tanzhijinghun");
                                if (auto_weapon) carry_object(weapon_dir+"dart")->wield();
                                break;  
                case "xuanyuan-axe1": 
                                set("class","knight");
                                set_name("������",({name}));
                                set_skill("hanshan-strike",special+50);
                                set_skill("windy-steps",special);
                                set_skill("xuanyuan-axe",special);
                                map_skill("parry","xuanyuan-axe");
                                map_skill("axe","xuanyuan-axe");
                                map_skill("unarmed","hanshan-strike");
                                map_skill("dodge","windy-steps");
                                set("perform_attack","axe.guifushengong");
                                set("perform_attack_2","unarmed.zhangjian");
                                set("perform_busy","dodge.fengliu");
                                if (auto_weapon) carry_object(weapon_dir+"axe")->wield();       
                                break;
                case "xuanyuan-axe2": 
                                set("class","knight");
                                set_name("������",({name}));
                                set_skill("hanshan-strike",special+50);
                                set_skill("windy-steps",special);
                                set_skill("xuanyuan-axe",special);
                                map_skill("parry","axe.xuanyuan-axe");
                                map_skill("axe","xuanyuan-axe");
                                map_skill("unarmed","hanshan-strike");
                                map_skill("dodge","windy-steps");
                                set("perform_attack","axe.jiuqipoxiao");
                                set("perform_attack_2","unarmed.zhangjian");
                                set("perform_busy","dodge.fengliu");
                                if (auto_weapon) carry_object(weapon_dir+"axe")->wield();       
                                break;
                case "softsword": 
                                set("class","swordsman");
                                set_name("��ū",({name}));
                                set_skill("yue-strike",special);
                                set_skill("shadowsteps",special+50);
                                set_skill("softsword",special);
                                map_skill("sword","softsword");
                                map_skill("parry","softsword");
                                map_skill("unarmed","yue-strike");
                                map_skill("dodge","shadowsteps");
                                set("perform_attack","sword.muyufeihong");
                                set("perform_attack_2","dodge.lianhuanjiao");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();     
                                break;                          
                case "ittouryu": 
                                set("npc_type","fighter_w");
                                set("class","ninja");
                                set_name("���",({name}));
                                set_skill("yue-strike",special);
                                set_skill("ghosty-steps",special);
                                set_skill("ittouryu",special);
                                map_skill("blade","ittouryu");
                                map_skill("unarmed","yue-strike");
                                map_skill("dodge","ghosty-steps");
                                set("perform_attack","blade.hyakki");
                                if (auto_weapon) carry_object(weapon_dir+"blade")->wield();     
                                break;
                case "ass-hammer": 
                                set("npc_type","fighter_w");
                                set("class","wolf");
                                set_name("����",({name}));
                                set_skill("wolf-strike",special);
                                set_skill("xueyeqianzong",special);
                                set_skill("assasin-hammer",special);
                                map_skill("hammer","assasin-hammer");
                                map_skill("parry","assasin-hammer");
                                map_skill("unarmed","wolf-strike");
                                map_skill("dodge","xueyeqianzong");
                                set("perform_attack_2","unarmed.duanhou");
                                if (auto_weapon) carry_object(weapon_dir+"hammer")->wield();    
                                break;                          
                case "pangu-hammer": 
                                set("npc_type","fighter_w");
                                set("class","yinshi");
                                set_name("���촸",({name}));
                                set_skill("pofeng-strike",special+50);
                                set_skill("zuixian-steps",special+20);
                                set_skill("pangu-hammer",special);
                                map_skill("hammer","pangu-hammer");
                                map_skill("parry","pangu-hammer");
                                map_skill("unarmed","pofeng-strike");
                                map_skill("dodge","zuixian-steps");
                                set("perform_attack","hammer.kaitianpidi");
                                set("perform_attack_2","unarmed.luanpofeng");
                                if (auto_weapon) carry_object(weapon_dir+"hammer")->wield();    
                                break;  
                default:        
                case "thunderwhip": 
                                set("npc_type","fighter_w");
                                set("class","yinshi");
                                set_name("����",({name}));
                                set_skill("pofeng-strike",special+50);
                                set_skill("zuixian-steps",special+20);
                                set_skill("pangu-hammer",200);
                                set_skill("thunderwhip",special);
                                map_skill("hammer","pangu-hammer");
                                map_skill("whip","thunderwhip");
                                map_skill("parry","thunderwhip");
                                map_skill("unarmed","pofeng-strike");
                                map_skill("dodge","zuixian-steps");
                                set("marks/hammerwhip",1); 
                                set("perform_attack","whip.tianleiyiji");
                                set("perform_attack_2","unarmed.luanpofeng");
                                if (auto_weapon) carry_object(weapon_dir+"whip")->wield();      
                                break;  
                case "yunlong": 
                                set("npc_type","fighter_w");
                                set("class","yinshi");
                                set_name("����",({name}));
                                set_skill("pofeng-strike",special+50);
                                set_skill("zuixian-steps",special+20);
                                set_skill("pangu-hammer",200);
                                set_skill("thunderwhip",special);
                                set_skill("celecurse",special);
                                set_skill("cursism",special);
                                map_skill("cursism","celecurse");
                                map_skill("hammer","pangu-hammer");
                                map_skill("whip","thunderwhip");
                                map_skill("parry","thunderwhip");
                                map_skill("unarmed","pofeng-strike");
                                map_skill("dodge","zuixian-steps");
                                set("marks/hammerwhip",1); 
                                set("perform_attack","whip.yunlongjiuxian");
                                set("perform_attack_2","unarmed.luanpofeng");
                                if (auto_weapon) carry_object(weapon_dir+"whip")->wield();      
                                break;  
                case "xinyue-dagger": 
                                set("npc_type","fighter_w");
                                set("class","wolfmount");
                                set_name("Ǭ��",({name}));
                                set_skill("wolf-strike",special);
                                set_skill("xueyeqianzong",special+20);
                                set_skill("xinyue-dagger",special-40);
                                set_skill("assasin-hammer",200);
                                map_skill("dagger","xinyue-dagger");
                                map_skill("parry","xinyue-dagger");
                                map_skill("unarmed","wolf-strike");
                                map_skill("dodge","xueyeqianzong");
                                set("perform_attack","dagger.douzhuanxingyi");
                                set("perform_attack_2","unarmed.duanhou");
                                if (auto_weapon) carry_object(weapon_dir+"dagger")->wield();    
                                break;  
                } 
        } else  {
// below are fighter_u types:                                   
                switch (random_choose) {
                case "dragonstrike": 
                                set("npc_type","fighter_u");
                                set_name("����",({name}));
                                set("class","beggar");
                                set_skill("dragonstrike",special+20);
                                set_skill("doggiesteps",special+80);
                                set_skill("dagou-stick",special);
                                map_skill("staff","dagou-stick");
                                map_skill("parry","dagou-stick");
                                map_skill("unarmed","dragonstrike");
                                map_skill("dodge","doggiesteps");
                                set("perform_attack_2","unarmed.xianglongwuhui");
                                break;
                case "taiji": 
                                set_name("����",({name}));
                                set("class","wudang");
                                set_skill("taiji",special);
                                set_skill("five-steps",special);
                                set_skill("taijiforce",200);
                                map_skill("force","taijiforce");
                                map_skill("unarmed","taiji");
                                map_skill("dodge","five-steps");
                                set("perform_attack_2","unarmed.nianzijue");
                                break;
                case "bazhentu": 
                                set_name("ʧ�����",({name}));
                                set("class","wudang");
                                set_skill("taiji",special);
                                set_skill("five-steps",special);
                                set_skill("taijiforce",200);
                                map_skill("force","taijiforce");
                                map_skill("unarmed","taiji");
                                map_skill("dodge","five-steps");
                                set("perform_attack_2","dodge.bazhentu");
                                break;
                case "doomstrike": 
                                set("npc_type","fighter_u");
                                set("class","fighter");
                                set_name("���ƶϻ�",({name}));
                                set_skill("doomstrike",special);
                                set_skill("doomsteps",special);
                                map_skill("unarmed","doomstrike");
                                map_skill("dodge","doomsteps");
                                set("perform_attack_2","unarmed.hantian");      
                                break;
                case "hanshan-strike": 
                                set("npc_type","fighter_u");
                                set("class","knight");
                                set_name("����",({name}));
                                set_skill("hanshan-strike",special);
                                set_skill("windy-steps",special);
                                map_skill("unarmed","hanshan-strike");
                                map_skill("dodge","windy-steps");
                                set("perform_attack_2","unarmed.zhangjian");
                                set("perform_busy","dodge.fengliu");    
                                break;
                case "yiyangzhi": 
                                set("npc_type","fighter_u");
                                set("class","shaolin");
                                set_name("һ��",({name}));
                                set_skill("yiyangzhi",special);
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special/2);
                                set_skill("puti-steps",special);
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","yiyangzhi");
                                map_skill("dodge","puti-steps");
                                set("perform_attack_2","unarmed.qiankun");
                                break;
                case "yizhichan": 
                                set("npc_type","fighter_u");
                                set("class","shaolin");
                                set_name("�黨",({name}));
                                set_skill("yizhichan",special);
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special/2);
                                set_skill("puti-steps",special);
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","yizhichan");
                                map_skill("dodge","puti-steps");
                                set("perform_attack_2","unarmed.nianhua");
                                break;
                case "enmeiryu": 
                                set("npc_type","fighter_u");
                                set("class","ninja");
                                set_name("�ϵ�",({name}));
                                set_skill("enmeiryu",special);
                                set_skill("ghosty-steps",special);
                                map_skill("unarmed","enmeiryu");
                                map_skill("dodge","ghosty-steps");
                                set("perform_attack_2","unarmed.shiden");
                                break;
                case "yaozhan": 
                                set("npc_type","fighter_u");
                                set("class","ninja");
                                set_name("��ȸ",({name}));
                                set_skill("enmeiryu",special);
                                set_skill("ghosty-steps",special);
                                map_skill("unarmed","enmeiryu");
                                map_skill("dodge","ghosty-steps");
                                set("perform_attack_2","unarmed.shimon");
                                break;
                case "mukuha": 
                                set("npc_type","fighter_u");
                                set("class","ninja");
//                              set("mark/true_mukuha",1);
                                set_name("����",({name}));
                                set_skill("enmeiryu",special);
                                set_skill("ghosty-steps",special);
                                map_skill("unarmed","enmeiryu");
                                map_skill("dodge","ghosty-steps");
                                set("perform_attack_2","unarmed.mukuha");
                                break;
                case "tenderzhi": 
                                set("npc_type","fighter_u");
                                set("class","taoist");
                                set_name("���",({name}));
                                set("gender","Ů��");
                                set_skill("tenderzhi",special);
                                set_skill("iron-cloth",basic);
                                set_skill("puti-steps",special);
                                map_skill("unarmed","tenderzhi");
                                map_skill("dodge","puti-steps");
                                set("perform_attack_2","unarmed.qiankun");
                                break;
                case "wolf-strike": 
                                set("npc_type","fighter_u");
                                set("class","wolfmount");
                                set_name("����צ",({name}));
                                set_skill("wolf-strike",special);
                                set_skill("xueyeqianzong",special);
                                map_skill("unarmed","wolf-strike");
                                map_skill("dodge","xueyeqianzong");
                                set("perform_attack_2","unarmed.duanhou");
                                break;
                case "wolf-claw": 
                                set("npc_type","fighter_u");
                                set("class","wolfmount");
                                set_name("����צ",({name}));
                                set_skill("wolf-claw",special);
                                set_skill("xueyeqianzong",special);
                                map_skill("unarmed","wolf-claw");
                                map_skill("dodge","xueyeqianzong");
                                set("perform_attack_2","unarmed.ningxie");
                                break;
                case "nine-moon-claw": 
                                set("npc_type","fighter_u");
                                set("class","shenshui");
                                set("gender","Ů��");
                                set_name("����צ",({name}));
                                set_temp("nine-moon-force_poison",special*2);
                                set_skill("nine-moon-claw",special);
                                set_skill("nine-moon-steps",special);
                                set_skill("nine-moon-force",200);
                                map_skill("force","nine-moon-force");
                                map_skill("unarmed","nine-moon-claw");
                                map_skill("dodge","nine-moon-steps");
                                set("perform_busy","dodge.lianhuanbu");
                                set("force_factor",100);
                                break;
                case "lingxi-zhi": 
                                set("npc_type","fighter_u");
                                set("class","");
                                set_name("��˿��",({name}));
                                set_skill("lingxi-zhi",special);
                                set_skill("iron-cloth",special);
                                set_skill("yijinjing",special-50);
                                map_skill("unarmed","lingxi-zhi");
                                map_skill("iron-cloth","yijinjing");
                                set("force_factor",100);
                                set("no_busy",10);
                                break;
                case "yue-strike": 
                                set("npc_type","fighter_u");
                                set("class","");
                                set_name("�ٻ�ȭ",({name}));
                                set_skill("yue-strike",special);
                                set_skill("iron-cloth",special);
                                set_skill("yijinjing",special-50);
                                map_skill("unarmed","yue-strike");
                                map_skill("iron-cloth","yijinjing");
                                set("force_factor",100);
                                set("no_busy",10);
                                break;
                case "luoriquan": 
                                set("npc_type","fighter_u");
                                set("class","bat");
                                set_name("����",({name}));
                                set_skill("meng-steps",special);
                                set_skill("luoriquan",special+50);
                                map_skill("unarmed","luoriquan");
                                map_skill("dodge","meng-steps");
                                set("perform_attack","unarmed.luori");
                                set("perform_busy","dodge.huanyinqianchong");
                                break;
                case "shadowsteps": 
                                set("class","swordsman");
                                set_name("������",({name}));
                                set_skill("yue-strike",special);
                                set_skill("shadowsteps",special+50);
                                set_skill("softsword",special);
                                set_skill("cloudforce",200);
                                map_skill("force","cloudforce");
                                map_skill("sword","softsword");
                                map_skill("parry","softsword");
                                map_skill("unarmed","yue-strike");
                                map_skill("dodge","shadowsteps");
                                set("perform_attack","dodge.lianhuanjiao");
                                break;  
// below are ironman types:
                case "jin-gang": 
                                set("npc_type","ironman");
                                set("class","lama");
                                set_name("����",({name}));
                                set_skill("bloodystrike",special);
                                set_skill("cloudstaff",special);
                                set_skill("iron-cloth",basic);
                                set_skill("jin-gang",special);
                                map_skill("parry","cloudstaff");
                                map_skill("staff","cloudstaff");
                                map_skill("iron-cloth","jin-gang");
                                map_skill("unarmed","bloodystrike");
                                map_skill("dodge","windy-steps");
                                set("perform_attack","staff.longxianyuye");
                                set("perform_busy_2","unarmed.fefawubian");
                                if (auto_weapon) carry_object(weapon_dir+"staff")->wield();     
                                break;
                case "sl-hammer": 
                                set("npc_type","ironman");
                                set("class","shaolin");
                                set_name("����",({name}));
                                set_skill("dabei-strike",special);
                                set_skill("liuxing-hammer",special+50);
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special/2);
                                set_skill("puti-steps",special);
                                map_skill("parry","liuxing-hammer");
                                map_skill("hammer","liuxing-hammer");
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","dabei-trike");
                                map_skill("dodge","puti-steps");
                                set("perform_attack","hammer.fanbei");
                                if (auto_weapon) carry_object(weapon_dir+"hammer")->wield();    
                                break;
                case "sl-axe": 
                                set("npc_type","ironman");
                                set("class","shaolin");
                                set_name("�÷�",({name}));
                                set_skill("dabei-strike",special);
                                set_skill("wuche-axe",special);
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special/2);
                                set_skill("puti-steps",special);
                                map_skill("parry","wuche-axe");
                                map_skill("axe","wuche-axe");
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","dabei-trike");
                                map_skill("dodge","puti-steps");
                                set("perform_attack","axe.sanbanfu");
                                set("perform_busy_2","unarmed.fefawubian");
                                if (auto_weapon) carry_object(weapon_dir+"axe")->wield();       
                                break;
                case "sl-spear": 
                                set("npc_type","ironman");
                                set("class","shaolin");
                                set_name("�����",({name}));
                                set_skill("dabei-strike",special);
                                set_skill("duanhun-spear",special);
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special/2);
                                set_skill("puti-steps",special);
                                map_skill("parry","duanhun-spear");
                                map_skill("spear","duanhun-spear");
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","dabei-trike");
                                map_skill("dodge","puti-steps");
                                set("perform_attack","spear.suomengchanhun");
                                set("perform_busy_2","unarmed.fefawubian");
                                if (auto_weapon) carry_object(weapon_dir+"spear")->wield();     
                                break;
                case "sl-staff": 
                                set("npc_type","ironman");
                                set("class","shaolin");
                                set_name("��ħ��",({name}));
                                set_skill("dabei-strike",special);
                                set_skill("fumostaff",special+80);
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special/2);
                                set_skill("puti-steps",special);
                                map_skill("parry","fumotaff");
                                map_skill("staff","fumostaff");
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","dabei-strike");
                                map_skill("dodge","puti-steps");
                                set("perform_attack","staff.hequhecong");
                                if (auto_weapon) carry_object(weapon_dir+"staff")->wield();     
                                break;
                default:        
                case "sl-yijinjing": 
                                set("npc_type","ironman");
                                set("class","shaolin");
                                set_name("���",({name}));
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special);
                                set_skill("puti-steps",special);
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","yijinjing");
                                map_skill("dodge","puti-steps");
                                set("force_factor",100);
                                set("no_busy",10);
                                break;
                                case "sq-female":
                                set("npc_type","magician");
                                set("class","taoist");
                                set("my_type","sq-female");
                                set_name("�����ɹ�",({name}));
                                set("gender","Ů��");
                                set_skill("necromancy",special);
                                set_skill("notracesnow",special);
                                set_skill("tenderzhi",special);
                                set_skill("gouyee",200);
                                map_skill("spells","necromancy");
                                map_skill("force","gouyee");
                                map_skill("unarmed","tenderzhi");
                                map_skill("dodge","notracesnow");
                                set("cast_attack","invocation");
                                break;
                case "sq-female2":
                                set("npc_type","magician");
                                set("class","taoist");
                                set("my_type","sq-female");
                                set_name("�����ɹ�",({name}));
                                set("gender","Ů��");
                                set_skill("necromancy",special);
                                set_skill("notracesnow",special);
                                set_skill("tenderzhi",special);
                                set_skill("gouyee",200);
                                set("open_sesame",1);
                                set("open_sesame/taoist",1);
                                set("sen",special*20);
                                set("max_sen",special*20);
                                set("eff_sen",special*20);
                                set("mana",special*10);
                                set("max_mana",special*10);
                                map_skill("spells","necromancy");
                                map_skill("force","gouyee");
                                map_skill("unarmed","tenderzhi");
                                map_skill("dodge","notracesnow");
                                set("cast_attack","superbolt");
                                break;
                case "sq-male":
                                set("npc_type","magician");
                                set("class","taoist");
                                set("my_type","sq-male");
                                set_name("��������",({name}));
                                set_skill("alchemy",special);
                                set_skill("notracesnow",special+20);
                                set_skill("tenderzhi",special+20);
                                set_skill("gouyee",200);
                                set_skill("snowshade-sword",special+50);
                                set_skill("scratching",special);
                                set_skill("scratmancy",special);
                                map_skill("sword","snowshade-sword");
                                map_skill("scratching","scratmancy");
                                map_skill("force","gouyee");
                                map_skill("unarmed","tenderzhi");
                                map_skill("dodge","notracesnow");
                                map_skill("parry","snowshade-sword");
                                set_temp("shield_force/type","mana");
                                set_temp("shield_force/ratio",450);
                                set_temp("shield_force/msg",
                                MAG"$N��ʽ����$n��ǰ����֮�⣬����ţ�뺣,��ʧ�������С�\n"NOR);
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;  
                case "sq-male2":
                                set("npc_type","magician");
                                set("class","taoist");
                                set("my_type","sq-male2");
                                set_name("��ʦ����",({name}));
                                set_skill("alchemy",special);
                                set_skill("notracesnow",special+20);
                                set_skill("tenderzhi",special+20);
                                set_skill("gouyee",200);
                                set_skill("snowshade-sword",special+50);
                                set_skill("scratching",special);
                                set_skill("scratmancy",special);
                                map_skill("sword","snowshade-sword");
                                map_skill("scratching","scratmancy");
                                map_skill("force","gouyee");
                                map_skill("unarmed","tenderzhi");
                                map_skill("dodge","notracesnow");
                                map_skill("parry","snowshade-sword");
                                set_temp("shield_force/type","mana");
                                set_temp("shield_force/ratio",450);
                                set_temp("shield_force/msg",
                                MAG"$N��ʽ����$n��ǰ����֮�⣬����ţ�뺣,��ʧ�������С�\n"NOR);
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;                  
                case "dz-an":
                                set("npc_type","magician");
                                set("class","lama");
                                set("my_type","dz-an");
                                set_name("�ߺ�����",({name}));
                                set_skill("kwan-yin-spells",special);
                                set_skill("jin-gang",special);
                                set_skill("iron-cloth",special);
                                set_skill("cloudstaff",special);
                                set_skill("bloodystrike",special);
                                set_skill("gouyee",200);
                                map_skill("spells","kwan-yin-spells");
                                map_skill("force","gouyee");
                                map_skill("iron-cloth","jin-gang");
                                map_skill("unarmed","bloodystrike");
                                map_skill("staff","cloudstaff");
                                map_skill("parry","cloudstaff");
                                set("cast_attack","an");
                                if (auto_weapon) carry_object(weapon_dir+"staff")->wield();
                                break;
                }
}
} 
auto_smart_fight()
{
        int i,n,j,count;
        string pfm_weapon_attack,pfm_dodge_busy;
        string pfm_unarmed_attack,pfm_unarmed_busy;
        object *enemy, me, weapon;
        
        me= this_object();
        
        if (me->query("npc_type")=="healer") {
                help_friend();
        }       
                
        if (me->query("npc_type")=="magician") {
                switch (me->query("my_type")) {
                        case "sq-male": alchemy_fight();
                                        break;
                        case "sq-male2": sheet_fight();
                                        break;
                        case "sq-female":
                        case "sq-female2":
                        case "dz-an":   cast_attack();
                                        break;
                        default:                
                        }       
        }       
        
        pfm_weapon_attack = me->query("perform_attack");
        pfm_unarmed_attack = me->query("perform_attack_2");
        pfm_dodge_busy = me->query("perform_busy");
        pfm_unarmed_busy = me->query("perform_busy_2");
        
        n=1;
//      if (pfm_unarmed_busy) n=8;
        if (pfm_dodge_busy) n =3;
        
        enemy = this_object()->query_enemy();
        ask_help(); 
        if (me->query("npc_type")=="healer")    return;
                
        if (me->query("zombie-killer")) {
                count=0;
                for (j=0;j<sizeof(enemy);j++) {
                        if (enemy[j]->is_zombie()) count++;
                }
                if (count>=3)
                        command("perform zombie-wp1");
        }
        
        
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<n*this_object()->query("combat_exp")) {
                                if (pfm_dodge_busy)
                                        this_object()->perform_action(pfm_dodge_busy);                  
                        }
                        if (enemy[i]->is_busy() || n==1 ) {
                                if (!me->query_temp("weapon")) {
                                        if (pfm_unarmed_attack)
                                        this_object()->perform_action(pfm_unarmed_attack);
                                } else if (pfm_weapon_attack)
                                        this_object()->perform_action(pfm_weapon_attack);       
                        }
                }
        }
} 
void cast_attack() {
        string cast_type;
        cast_type=this_object()->query("cast_attack");
        this_object()->cast_spell(cast_type);
        this_object()->set("mana",this_object()->query("max_mana"));
        return;
}  
void sheet_fight() { 
        object obj, soldier, me;
        int spells;
        me = this_object();
        if( me->query_temp("max_guard") > 4 ) return;
        message_vision("$N���о��񣬼�����ζ�������һ����ʦ������������\n", me);
        me->start_busy(1);
        spells = me->query_skill("scratching");
        seteuid(getuid());
        if( random(10) < 5 )
                soldier = new("/obj/npc/heaven_soldier");
        else
                soldier = new("/obj/npc/hell_guard");
        soldier->move(environment(me));
        soldier->invocation(me, spells);
        soldier->set("possessed", me);
        me->add_temp("max_guard",1);
        message_vision(HIB "\n$N����$n�ı��󺰵�������ɱ��\n" NOR, me, soldier );
} 
void alchemy_fight() {
                
        string weapon_name,x;
        int i;
        object *enemy,weapon,owner,victim;
        switch( random(4)){
                case 0: weapon_name="zhui";
                        break;
                case 1: weapon_name="chain";
                        break;
                case 2: weapon_name="mirror";
                        break;
                case 3: weapon_name="flag";
                        break;
                }
        switch (weapon_name) {
                case "mirror": x="m";break;
                case "flag" : x="f";break;
                case "chain": x="c";break;
                case "zhui": x="z";break;
        }
        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        while(i--)       {
                weapon = new("/obj/specials/alchemy/magic/"+weapon_name);
                weapon->move(this_object());
                if(enemy[i] && objectp(enemy[i]) && environment(this_object())==environment(enemy[i])) {
                        if (!userp(enemy[i])) { 
                                if(owner=enemy[i]->query("possessed")) {
                                        victim = owner;
                                        if (!victim->is_fighting()) {
                                                kill_ob(victim);
                                                command("shoot"+x+" "+victim->query("id"));
                                        }
                                }
                        }
                        command("shoot"+x+" "+enemy[i]->query("id"));
                        this_object()->stop_busy();
                }
        }
        this_object()->start_busy(2);
}  
void ask_help() {
        object me, *enemy, *inv, ob;
        string type;
        int i, j;
        
        me= this_object();
        type = me->query("dungeon_npc");
        if (!type) return;
        enemy = me->query_enemy();
        inv = all_inventory(environment(this_object()));
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if (userp(ob) || !ob->is_character() || ob->is_corpse() 
                        || ob->query("dungeon_npc")!=type || ob==me) {
                        continue;
                }
                for (j=0;j<sizeof(enemy);j++) {
                        if (ob->is_fighting(enemy[j])) {
                                continue;
                                }
                        ob->kill_ob(enemy[j]);
                }               
        }
}  
void help_friend() {
        object me, *inv, ob;
        string type;
        int i, j;
        
        me= this_object();
        type = me->query("dungeon_npc");
        inv = all_inventory(environment(this_object()));
        
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if (userp(ob) || !ob->is_character() || ob->is_corpse() 
                        || ob->query("dungeon_npc")!=type) {
                        continue;
                }
                if (ob->query("kee")>ob->query("max_kee")/3 
                        && ob->query("eff_kee")>ob->query("max_kee")/3
                        && ob->query("gin")>ob->query("max_gin")/3 
                        && ob->query("eff_gin")>ob->query("max_gin")/3
                        && ob->query("sen")>ob->query("max_sen")/3 
                        && ob->query("eff_sen")>ob->query("max_sen")/3)
                {
                        continue;
                }
                if (ob!=me)
                        message_vision(HIY "$N�����ڹ�������������$n���ģ������ؽ���������$n����....\n\n"NOR,me,ob);
                        else
                                message_vision(HIY "$N�����ڹ��������ؽ�������������ת....\n\n"NOR,me);
                        call_out("heal_him", 6, me, ob);
                        me->start_busy(2);
                        return;
                                
        }
        return;
}  
int heal_him(object me, object target)
{
        int amount;
        amount=6000;
        if (!objectp(me)) return 0;
        if (me->is_unconcious()) return 0;
        
        if (!present(target,environment(me))) {
                tell_object(me,"��Ҫ���ε����Ѿ����������ˡ�\n");
                return notify_fail("");
                }
        if (target!=me)
        message_vision(HIY"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n"NOR,me,target);
        else 
        message_vision(HIY"���˲��ã�$N�³�һ����Ѫ����ɫ������������ˡ�\n"NOR,me);
        target->receive_curing("kee", amount);
        target->receive_curing("sen", amount/2);
        target->receive_curing("gin", amount/2);
        if (target->query("kee")+ amount<target->query("max_kee"))
                target->add("kee",amount);
                else target->set("kee",target->query("max_kee"));
        if (target->query("sen")+ amount/2<target->query("max_sen"))
                target->add("sen",amount/2);
                else target->set("sen",target->query("max_sen"));
        if (target->query("gin")+ amount/2<target->query("max_gin"))
                target->add("gin",amount/2);
                else target->set("gin",target->query("max_gin"));
        return 1;
}  
void die(){
        object book;
        int i;
        message_vision(HIR"\n$N�ҽ�һ��������ȥ������һ��������ʧ�ˡ�\n"NOR,this_object());     
        book = new("obj/money/silver");
        book->set_amount(10);
        book->move(environment(this_object()));
        destruct(this_object());        
}   
