inherit NPC;
int give_him();
void create()
{
        set_name("��ƨ�ɵ�С����", ({ "boy","little boy" }) );
        set("gender", "����" );
        set("age", 5);
        set("combat_exp", 5);
        set("attitude", "friendly");
        set("per",2);
        set("chat_chance", 5);
        set("chat_msg", ({
                "��ƨ�ɵ�С�����Ĵ���ˮ�棬����ƬƬ����.\n",
                "��ƨ�ɵ�С����˵����̫�����ˣ���\n",
        }) );
        setup();
}