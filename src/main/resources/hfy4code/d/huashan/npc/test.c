 inherit NPC;
void create()
{
        set_name("����Ʒ", ({ "tester" }) );
        set("gender", "����" );
        set("age", 40);
        set("long",
                "һ��Ϊ��������ձ�����С���ˣ�\n");
          set("combat_exp", 5);
        set("attitude", "friendly");
        setup();
}  
void die(){
    object killer;
    string location;
    int difficulty;     
    location="���п�";
    
    killer = this_object()->query_temp("last_damage_from");
         
    if(!killer->query("m_killer/tester")) {
         killer->set("m_killer/tester",1);
         difficulty =1;
         this_object()->master_reward(this_object(),killer,location,difficulty);
        }
        
    ::die();
} 
void master_reward(object victim, object killer, string location, int difficulty)
{
    object money_reward;
    int i, pot, combat_exp, score;
    
    pot = difficulty*200;
    combat_exp = difficulty*10000;
    score = difficulty*50;
    killer->add("potential",difficulty*200);
    killer->add("combat_exp", difficulty*10000);
    killer->add("score", difficulty*50);
    
    for(i=0; i<difficulty+1; i++) {
        money_reward = new("/obj/money/tenthousand-cash");
        money_reward ->move(killer);
        }
        write(sprintf("�㱻������%sǱ�ܡ�\n", CHINESE_D->chinese_number(pot)));
        write(sprintf("�㱻������%s����ֵ��\n", CHINESE_D->chinese_number(combat_exp)));
        write(sprintf("�㱻������%s���ۡ�\n", CHINESE_D->chinese_number(score)));
CHANNEL_D->do_sys_channel(
        "info",sprintf("%s��%s��%s��ɱ%s��", NATURE_D->game_time(),
                      killer->name(), location, this_object()->name()) ); 
//      for example �㱻������,xxxxxǱ�ܣ�xxxxx����ֵ, xxxxx����, xxxxxx
//�ƽ� 
/*      Also, put an announcement in ���� 'info' channel.      
        varibles are: date, killer, master, location, 
        date= mud time, do we have a ������ in Fy ?
        killer = xxder;
        victim = tester;
        location = ���п�;
        
        
        the announcement will be similar to:
         [����] ĳ��ĳ��ĳ��,С�����ڲ��пڻ�ɱ����Ʒ! (���Ƶ�һ��)
         
         
*/       
}   
