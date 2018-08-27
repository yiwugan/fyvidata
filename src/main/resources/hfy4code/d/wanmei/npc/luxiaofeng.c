 inherit NPC;
void create()
{
        set_name("½С��", ({ "lu", "lu xiaofeng" }) );
        set("gender", "����");
        set("age", 34);
        set("title","������Ϭһ��ͨ");
        set("long",
"����üë��½С��\n"
               );  
        set("attitude", "peaceful");
        set("combat_exp", 3000000);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 50);
        set("no_arrest",1);
        set("reward_npc", 1);
        set("difficulty", 5);
        set("int",51);
        set("cor",50);
        set("cps",60);
        
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        
        set("skill_public",1);
        set("marks/�����Ϭ",1);
        
        set_skill("force", 180);
        set_skill("unarmed", 150);
        set_skill("parry",150);
        set_skill("lingxi-zhi",220);
        set_skill("six-chaos-sword",150);
        set_skill("sword",150);
        
        map_skill("unarmed","lingxi-zhi");
        map_skill("parry","six-chaos-sword");
        map_skill("sword","six-chaos-sword");
        
        set_temp("xinyoulingxi", 1); 
                
        setup();
        carry_object("/obj/armor/cloth")->wear();
} 
void init()
{
        ::init();
        if (this_player()->query("marks/��ӥ��")){
                command("say ��л���ӥ������.");
                if (!this_player()->query_skill("doomsword",1)){
                command ("say ����Ϊ�����粻����������Щ����ɡ�");
                message_vision("$N���˿��������ֻ���ҵ��书�Ǽ��к��ļ��츳�߲������ɡ���\n",this_object());
                command ("say �㻹�Ǻú���һ��ɣ�����ǿ����ʦ���кܶࡣ\n");
                this_player()->set("marks/lu_teach",1);
                this_player()->delete("marks/��ӥ��");
                } else command ("say ��ϧ�������ŵĴ���,����ʹ���㹦����.");
        }
        if (this_player()->query("marks/kill_ximen") && this_player()->query_skill("lingxi-zhi")){
                command ("say �㾹Ȼʤ�������Ŵ�ѩ,���ն�������Ϊ!!!");
                command ("say �ҵľ���[������Ϭ]�ʹ�����ɡ�");
                this_player()->set("marks/�����Ϭ",1);
                this_player()->delete("marks/kill_ximen");
                this_player()->delete("marks/won_lu");
        }
        add_action("do_killing", "kill");
                                                
} 
int recognize_apprentice(object ob){
        if ( (int)this_player()->query("marks/lu_teach")) {
                        return 1;
                }       
        return 0;
}  
void win_enemy(object loser)
{
    command("say ����,���ɣ�\n");
} 
void lose_enemy(object winner)
{
    if (this_player()->query_skill("lingxi-zhi")) {
    command("say ��!��!��Ĺ����ʤ������,��Ƿֻ�ǻ����ѡ�");
    winner->set("marks/won_lu",1);
    } else command ("say ���º�����!");
}  
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        if(victim->query("id")=="lu" || victim->query("id")=="lu xiaofeng")
        {
            this_object()->remove_all_enemy();
            command ("say �ã����ȶԸ���!");
            return 0;
        } 
    }
    return 0;
} 
int accept_fight(object me)
{
        object skinmask;
        object who;
        
        if (this_object()->is_fighting() || this_object()->is_busy())
                return notify_fail("½С������æ���أ�û�պ�����\n");
        who=this_object();
                
        if (who->query("kee")<who->query("max_kee") || who->query("eff_kee")<who->query("max_kee")
        || who->query("sen")<who->query("max_sen") || who->query("eff_sen")<who->query("max_sen")
        || who->query("gin")<who->query("max_gin") || who->query("eff_gin")<who->query("max_gin"))
                {
                        return notify_fail("½С����������,û������.\n");
                } 
        return 1;
}    
