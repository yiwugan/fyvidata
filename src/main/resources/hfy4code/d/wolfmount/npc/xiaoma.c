#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("С��", ({"xiao ma","ma"}) );
        set("title" , "��ŭ��");
        set("gender", "����" );
        set("age", 22);
        set("agi",30);
        set("per", 30);
                set("no_arrest",1);
                set("no_heal",1);
        set("str",100);
        set("long",
        "һ����ǿ��������ȫ�������������Ե�С����˶������з�ŭ��С��\n�������˿ڣ����ƺ����԰��������������壩һ�¡�\n"
        );
        set("force_factor", 50);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 2000);
        set("eff_kee", 2000);
        set("eff_sen", 2000);
        set("gin", 2000);
        set("kee", 2000);
        set("sen", 2000);
        set("max_force", 2000);
        set("force", 2000);
        set("combat_exp", 2999999);
        set("score", 30000);
        set("chat_chance",1);     
        set("chat_msg",({
                "С���ս���ȭͷ����ŭ�Ļ���������ȼ�ա�\n",
        "��С�գ�С�գ���С����Ϫˮ������ǰ����������ѪȾ�����峺�羵��Ϫˮ��\n",
        }) );
        set_skill("move", 150);
        set_skill("force", 100);
        set_skill("parry", 150);
        set_skill("literate", 100);
                set_skill("dodge", 100);
        set_skill("unarmed",200);
                setup();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                add_action("do_cure", "cure");
                add_action("do_answer","answer");
                add_action("do_accept","accept");
        }
} 
int do_cure(string arg)
{
        object me;
        me = this_player();
        if( arg != "xiao ma" ) 
                return notify_fail("��ҪΪ˭���ƣ�\n");
        else if( this_object()->query("xiaoma_cured") )
                return notify_fail("С��˵�������鷳�ˣ��ҵ������Ѿ������ˣ�\n");
        else
        {
                if ( me->query("force") < 1000)
                {
                        return notify_fail("�����������������������������ƣ�\n");
                }
                else
                {
                        write(HIW "��ȫ����ɣ�������ΪС���˹����ˡ�\n"NOR);
                        message_vision(HIW"С����ʹ���Ť�����������ƽ����������������һʱ˵����������\n"NOR , me);
                        me->add("force",-1000);
                        this_object()->set("xiaoma_cured",1);
                        me->start_busy(5);
                        call_out("ask_help", 5, me);
                        return 1;
                }       
        }
        return 1;
} 
void ask_help(object me)
{
        object obj;
        if ( me->query("����B/̩ɽ_�ճ�") )
        {
                message_vision(HIY"С��������۾�ͻȻ������������һ����ֵ�������$N��\n"NOR, me);
                message_vision(HIY"С��ȭ˵������λ"+RANK_D->query_respect(me)+"����֪�Ƿ������Ҿȳ�С�գ���Answer Yes��No��\n"NOR, me);
                me->set_temp("marks/wolf_xiaoma_asking",1);
        }
        else
        {
                message_vision(HIY"һ�����С��������۾�ͻȻ�����������м��Ŀ���$N��\n"NOR, me);
                message_vision(HIY"С����$Nһ��ȭ���������ҵ����Ʋ����󰭣���֪�ɷ����鷳��λӢ�ۣ�\n���Ҿȳ���Ƥ��С�գ�������Accept Yes��No��\n"NOR, me);
                me->set_temp("marks/wolf_xiaoma_questing",1);
                return;
        }
} 
int do_answer(string arg)
{
        object me, obj;
        object room; 
        obj = this_object();
        me =this_player();
        if(!me->query_temp("marks/wolf_xiaoma_asking")) return 0;
        
        if( arg == "yes" || arg == "YES" )
        {
                me->delete_temp("marks/wolf_xiaoma_asking"); 
                message_vision("$N�ս�ȭͷ����С�ձ�̫��ʹ�ߵ�ҩ����ƣ����Ǿ͵�̫�����Ļ�����\n̫��ʹ�߾�һ��ս�������ټ���\n", obj);
                me->set_temp("marks/wolf_xiaoma_good", 1); 
                message_vision("$Nת����Զ���ĺ�����ȥ......\n", obj);
                obj->set("chat_chance",0);   
                room = find_object("/d/wolfmount/flowerboat");
                if(!objectp(room)) room = load_object("/d/wolfmount/flowerboat");
                obj->move(room);
                return 1;
        }
        else if ( arg == "no" || arg == "NO" )
        {
           message_vision("$N��ɫ��Ȼ������"+me->name()+"Ҳ�ﲻ���ң�\n", obj);
                me->delete_temp("marks/wolf_xiaoma_asking"); 
                return 1;
        }
        else 
        {
                tell_object(me, name()+"�����Ҳ������������˼����\n");
                return 1;
        }
} 
int do_accept(string arg)
{
        object me, obj;
        obj = this_object();
        me =this_player();
        if(!me->query_temp("marks/wolf_xiaoma_questing")) return 0;
        
        if( arg == "yes" || arg == "YES" )
        {
                message_vision("$N����Ц������л��λӢ�ۣ�\n", obj);
                me->delete_temp("marks/wolf_xiaoma_questing"); 
                message_vision("$N��ɫ���ص���С�ձ�̫��ʹ�ߵ�ҩ�������ƣ�ֻ��ɱ��̫��ʹ�߲Ż������ƣ�\n", obj);
                me->set_temp("marks/wolf_xiaoma_normal", 1); 
                obj->set("chat_chance",0);
                return 1;
        }
        else if ( arg == "no" || arg == "NO" )
        {
                message_vision("$N��̾һ�������˲������Լ�������ƴ��һ����\n", obj);
                message_vision("$Nת����ȥ���µ�����Ӱ������Զ......\n", obj);
                me->delete_temp("marks/wolf_xiaoma_questing");
                destruct(obj);
                message_vision("$Nʧ�����ǣ������ѵ���Ϊ�Լ���ų����Ϊ�е���ֺ�ڣ�\n",me);
                me->add("score",-100);
                return 1;
        }
        else 
        {
                tell_object(me, name()+"�����Ҳ������������˼����\n");
                return 1;
   }
} 
void die()
{
        object xiaolin;
        if (xiaolin = present("xiao lin",environment(this_object())))
        {
                xiaolin->set("xiaoma_died",1);
        }
        ::die();
}  
