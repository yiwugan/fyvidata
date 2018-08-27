 inherit NPC;
#include <ansi.h>
int proceed(); 
void create()
{
        set_name("���ﳤ��", ({ "baili", "baili changqing"}) );
        set("nickname", HIC "�ɶ�����"NOR);
        set("gender", "����" );
        set("age", 54);
        set("per", 25);
        set("int", 28);
        set("attitude","friendly");
        
        set("force_factor", 30);
        set("max_force", 1000);
        set("force", 1000);
        set("attitude", "peaceful");
        
        set("combat_exp", 2800000);
        set("score", 90000);
        
        set_skill("perception",150);
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("dragonstrike", 180);
        set_skill("cloudsforce", 200);
        set_skill("tie-steps", 150);
                
        map_skill("unarmed", "draginstrike");
        map_skill("force", "cloudsforce");
        map_skill("dodge", "tie-steps");
        
        switch (random(5)) {
                case 0: set("resistance/sen",30);
                        break;
                case 1: set("resistance/gin",30);
                        break;
                default: set("resistance/kee",30);
                }
   
        set("inquiry",  ([
                        "gui dong jing" : (: proceed :),
                        "gui dongjing" :(: proceed :),
                        "guidongjing":(: proceed :),
                        "�鶫��":(: proceed :),
                ]) );
        set("chat_chance",1);
        set("chat_msg",({
                "���ﳤ��Ե˶���������ұ��������ɱ�㣬����......\n\n���а�......��\n",       
        }));    
        set("long",
                "������ĸߴ��ΰ��˫Ŀ���ⱬ�䡣��������Զ���ĳ����ھֵ����ˡ�"
                );
        setup();
    carry_object("/obj/armor/cloth")->wear();
} 
void init()
{
        object me;
        ::init();
        me = this_player();
        if( !query_heart_beat(this_object()) ) set_heart_beat(1); 
        if(!NATURE_D->is_day_time() && me && environment(me) == environment() && !me->is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 2, me);
        }
} 
int greeting(object me)
{
        object room;
        if(!me || environment(me) != environment() || me->is_fighting()) return 1;
        if( userp(me) )
        {
                if( !me->query("m_success/�ھ��ڼ�") )
                {
                        command("say ��λ" + RANK_D->query_respect(me)+"���Ϸ���Ҫ�������ϸ������������õ����Ѿ�һ��ս......\nҲ�ã���������������֤�ɡ�\n");
                } else {
                        command("say ��λ" +RANK_D->query_respect(me)+"�����ｫ��һ����ս���ط���С���㻹��ȥ��ȫ�ĵط��ɡ�\n");
                        message_vision("$N����һ�ӣ�һ����͵ľ��罫$n�������ͳ����������¡�\n",this_object(),me);
                   room = find_object("/d/bawang/undertower2");
                        if(!room) room=load_object("/d/bawang/undertower2");
                        me->move(room);
                        message("vision", me->name()+"�������滺������������\n", environment(me), me);
                }
        }
        return 1;
} 
int proceed()
{
        object me;
        object room;
        object note;
        me = this_player();
        if(NATURE_D->is_day_time()){
                return 1;
        }
        if (me->is_fighting()) return 1;
        command("say ��λ" + RANK_D->query_respect(me)+"�������⡰������Ȯ�족���ڼ��ǹ鶫����\n");
        command("consider");
        command("say �Ϸ�Ҳ��������º�������Σ������Һ͵��ֵܶ�������
�鶫�����ڼ�ĵ��ˡ������Ҷ���ƴ�����ܾ��ˣ���������������\n\n\n");
        if(!me->query("m_success/�ھ��ڼ�") ){
                me->set("m_success/�ھ��ڼ�",1);
                me->add("score",100);
        }
        message_vision(HIR"�����ͻȻ����һ����Ц����������죬��ȥ�ɣ���\n"NOR, me);
        message_vision(HIW"һƬ���������İ������������ױȵ��ٶ���$N������
$N�Ѿ��޷���ܣ�ֻ�ñ�Ŀ����������\n"NOR, me);
        message_vision(HIR"\nֻ����$Nһ�����ȣ������ߣ���\n$nֻ����һ����ɽ��������������ػ�������������$n�������Ʊڶ�����
���ɵ���Ѫ���磬һ�������˹�ȥ��\n"NOR,this_object(),me);
        message_vision("���Ժ����У�$N������һƬ��Ҷ��������Ʈ�䣬�ƺ�����һ��������
ס��$N����������\n",me);
        room = find_object("/d/bawang/undertower2");
        if(!room) room=load_object("/d/bawang/undertower2");
        me->unconcious();
        me->move(room);
        message("vision", "������ͻȻ����һ����ȣ����أ�����һ����ֻ��"+me->name()+"������������Ʊڶ�����
�漴һ�������������ɳ�����ס��"+me->name()+"������ʹ"+me->name()+"�����建������������ߵĲݵ��ϡ�\n", environment(me), me);
        message("vision", "�����в��ϴ������أ�ž�����ľ��������ŭ�Ⱥ͵�߳����ö���ҡҡ��׹��
����㵽���㣬���ϵ��д���שʯ����ľ�ɳ����ڵײ㣬����һ������
���صľ��죬������Ȼ�������������������У�������Ӱ�ƺ������Ϸ���
�ɱ���ȥ��\n", environment(me), me);
        message("vision", "����һ�˴ӷ���������"+me->name()+"��ߣ��Ҵ�д��һ��ֽ��������"+me->name()+"���У�
�漴Ҳ׷�����϶�ȥ��\n", environment(me), me);
        note = new(__DIR__"obj/dingxi_note");
        if (note) note->move(me);
        return 1;
}       
