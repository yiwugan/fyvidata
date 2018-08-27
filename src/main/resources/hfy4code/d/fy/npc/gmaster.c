 // teacher.c
//Modified by justdoit 04/11/2001 
inherit NPC;
#include <ansi.h> 
int test_dart();
void create_level(object who,string name, int exp); 
void create()
{
    set_name("����", ({ "meng", "zha meng" }) );
    set("nickname", HIY "��ʨ��"NOR);
    set("gender", "����" );
    set("age", 32);
    set("skill_public",1);
    set("reward_npc", 1);
    set("difficulty", 4);
    
    set("force",500);
    set("force_factor",20);
    set("max_force",500);
    
    set("inquiry",      ([
        "mission" : (: test_dart :),
        "����" : (: test_dart :),
        ]) );
    set("int", 30);
    create_family("����", 21, "�׼ҵ���");
    set("long",
        "��ʨ�Ʋ����������׼ҵ��ӣ��˲��������ˬ���ҹ㽻���ѣ�
������������̵ģ�ֻҪΪ�ھֳ����������ͿϽ̣�\n"
        );
    set("chat_chance", 2);
    set("chat_msg", ({
        "����˵����������ھ����ⲻ��\n",
            "����˵�������ڣ�����������£�������\n",
            }) );
    set("attitude", "peaceful");
                switch (random(3)) {
                case 0: set("resistance/sen",30);
                        break;
                case 1: set("resistance/gin",30);
                   break;
                default: set("resistance/kee",30);
                }
    
    set_skill("unarmed", 80);
    set_skill("dabei-strike", 80);
    set_skill("literate", 80);
    set_skill("force", 80);
    set_skill("dodge",80);
    set_skill("parry",80);
    set_skill("move",80);
    set_skill("hammer",80);
    set_skill("xiaochengforce",80);
    set_skill("liuxing-hammer",80);
    set_skill("puti-steps",80);

    map_skill("force", "xiaochengforce");    
    map_skill("unarmed", "dabei-strike");
    map_skill("dodge","puti-steps");
    map_skill("move","puti-steps");
    map_skill("hammer","liuxing-hammer");
    
    set("combat_exp", 3500000);
    setup();
    carry_object(__DIR__"obj/jinzhuang")->wear();
} 
void init()
{
        ::init();
        add_action("do_accept", "accept");
} 
int recognize_apprentice(object ob)
{
    if((time() - ob->query("marks/��ʨ") ) > 1800  ){
        say("����˵�����㣮�������ܾ�ûΪ�ھֳ�������....\n");
        return 0;
    } 
    return 1;
} 
int test_dart()
{
    object me;
        
    me=this_player();
    if (random(100)>50  || query("marks/gived") )
    {
        set("marks/gived",1);
        command("say �����ھ�����û����Ҫ�����ڡ�");
        return 1;
    }
    command("say �����Ϲ�Ǯׯ��һ��������Ҫ�˵����������Ը��Э�����ǣ�(accept mission)");
    return 1;
} 
int do_accept(string arg)
{    
    object ob,cart,biaotou;
    object me,*team;
    int i, exp; 
    
    if (arg != "mission") return 0;
    me=this_player();
    team=me->query_team();
    if (sizeof(team)==0) team=({me}); 
   if (sizeof(team) != 0 && (team[0]!=me)) 
        return notify_fail("say ֻ�ж����������������ڡ�\n");
        
    for (i=0;i<sizeof(team);i++)
    {
        if (team[i]->query("combat_exp")<1000000)
        {
            command("say ����·;Σ�գ��ҿ���λ"+RANK_D->query_respect(team[i])+"�ƺ����ˣ�");
            return 1;
        }
        if (!intp(team[i]->query("deposit")) || team[i]->query("deposit")<1000000)
        {
            command("say ������Σ�յ��£��ҿ�"+RANK_D->query_respect(team[i])+"û���⳥������");
            return 1;
        }
        if (team[i]->query("combat_exp")>exp)
                exp= team[i]->query("combat_exp");
    } 
    
    /*
    if (random(100)>50 || query("marks/gived") || time() < me->query("marks/����")+7200)
    {
        set("marks/gived",1);
        command("say �������ˣ��Ѿ����˽�����֧���ˡ�");
        return 1;
    }
        */
        
 
//begin: modified by justdoit
        if (query("marks/gived"))
                {
                 command("say �������ˣ��Ѿ����˽�����֧���ˡ�");
                 return 1;
                }
//end: modified by justdoit 
    set("marks/gived",1);
    command("say �ðɡ���������ͷ�߰ɡ�");
    command("say ���ڿ���Ҫ��˫�ݵģ�һ·С�ġ�");
    
    me->set("marks/����",time());       
    say("һ���ڳ�����Ժʻ����\n");
        
    ob=new(__DIR__"obj/cart");
    ob->move(environment());
    cart=ob;
        
    biaotou=new(__DIR__"biaotou");
    biaotou->move(environment());
    biaotou->get_quest("/d/fy/cartway1");
    biaotou->set_cart(cart);
    biaotou->set_protector(team);
    biaotou->set("combat_exp",exp);
    create_level(biaotou,"biao",exp);
        
    ob=new("/d/fy/obj/biaoyin");
    ob->set_amount(10+random(10));
    ob->move(cart);
        
    ob=new(__DIR__"biaoshia");
    ob->move(environment());
    ob->set_leader(biaotou);
    ob->set_temp("protecting",cart);
    ob->set("combat_exp",exp/2);        
    create_level(ob,"biao",3*exp/4);
 
    ob=new(__DIR__"biaoshi1a");
    ob->move(environment());
    ob->set_leader(biaotou);
    ob->set_temp("protecting",cart);
    ob->set("combat_exp",exp/2);
    create_level(ob,"biao",exp/2);              
        
    ob=new(__DIR__"biaoshi1a");
    ob->move(environment());
    ob->set_leader(biaotou);
    ob->set_temp("protecting",cart);
    ob->set("combat_exp",exp/2);
    create_level(ob,"biao",exp/2);      
    
    for(i=0;i<sizeof(team);i++)
        team[i]->set_temp("protecting",cart);
        
    me->set_temp("protecting",cart);
    me->set_leader(biaotou);
    biaotou->go_now();
    return 1;   
} 
void reset()
{
    delete("marks/gived");
}  
void create_level(object who,string name, int exp)
{
        int level;
        level=100+130*(exp-1000000)/6500000;
        if (exp<1000000) level=100;
        if (exp>7500000) level=230;
        level=level*level/100;
        if (name=="biao") {
                
                who->command("say biao is me��");
                who->set("str",10+random(level/15));
                who->set("agi",10+random(level/8));
           who->set("cor",20+random(15));
                who->set("max_kee",1000+random(level*level/40));
                who->set("eff_kee",who->query("max_kee"));
                who->set("kee",who->query("max_kee"));
                who->set_skill("hammer", 70 + random(level/2));
                who->set_skill("parry", 70 + random(level/2));
                who->set_skill("dodge", 70 + random(level/2));
                who->set_skill("move", 70 + random(level/2));
                who->set_skill("changquan",50+random(level/2));
                who->set_skill("unarmed",70 + random(level/2));
        }
        if (name=="gangster") {
                who->set("str",10+random(level/12));
                who->set("agi",10+random(level/8));
                who->set("cor",20+random(15));
                who->set("max_kee",2500+random(level*level/40));
                who->set("eff_kee",who->query("max_kee"));
                who->set("kee",who->query("max_kee"));
                who->set("max_sen",who->query("max_kee")/2);
                who->set("max_gin",who->query("max_kee")/2);
                who->set("eff_sen",who->query("max_sen"));
                who->set("sen",who->query("max_sen"));
                who->set("eff_gin",who->query("max_gin"));
                who->set("gin",who->query("max_gin"));
                who->set_skill("parry", 70 + random(level/2));
                who->set_skill("dodge", 70 + random(level/2));
                who->set_skill("move", 70 + random(level/2));
                who->set_skill("blade",70+random(level/2));
                who->set_skill("fall-steps",70+random(level/2));
                who->set_skill("unarmed",70+ random(level/2));
                who->set_skill("yue-strike",50+random(level/8));
                who->set_skill("shortsong-blade",50+random(level/8));
        } 
}   
