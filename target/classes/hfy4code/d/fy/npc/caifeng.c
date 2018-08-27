 // waiter.c
inherit NPC;
int check_legal_name(string arg);
int check_legal_id(string arg); 
void create()
{
        set_name("�ϲ÷�", ({ "waiter" }) );
        set("gender", "����" );
        set("age", 52);
        set("long",
                "��λ�ϲ÷���Ц�����æ��������ʱ�Ĳ�һ���Լ����ϻ��ۡ�\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        setup();
        carry_object("/obj/armor/cloth")->wear(); 
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_ding", "ding"); 
        add_action("do_bu", "bu");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "�ϲ÷�Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����������·��ɡ�\n");
                        break;
                case 1:
                        say( "�ϲ÷��ü����˵������λ" + RANK_D->query_respect(ob)
                                + "���������ְ�����ﲻ���㡣\n");
                        break;
        }
} 

int do_bu(string arg){
        object gold, armor, me;
        int prop, i;
        string wname;
        me = this_player();
        if(!arg) {
                return notify_fail("��Ҫ��ʲô��\n");
        }
        armor = present(arg, me);
        if(!objectp(armor)) {
                return notify_fail("��Ҫ��ʲô��\n");
        }
        if(!armor->query("armor_prop")){
                return notify_fail("�ⲻ���·��������Է첹��\n");
        }
        if(!armor->query("owner")) {
                message_vision("$N���˿�$n���е�" + armor->name() + "˵���������ֵ�÷첹��\n", 
                                this_object(), me);
        } else {
                prop = armor->query("base_armor") - armor->query("armor_prop/armor");
        if(prop <= 0) {
                        return notify_fail("����·�����Ҫ�첹��" );
                } else if(prop <= 5) {
                        i = prop;
                } else if (prop <= 10){
                        i = 5 + (prop - 5)*2;
                } else {
                        i = 5 + 5*2 + (prop -10)*3;
                }
                gold = present("gold_money", me);
                if(!gold) {
                        return notify_fail("������û�н��ӡ�\n");
                } 
                if((int)gold->query_amount() < i) {
                        return notify_fail("������û���㹻�Ľ��ӣ���Ҫ����" + chinese_number(i) + "����\n");
                }
                gold->add_amount(-i);
                if(armor->query("equipped") == "worn") {
                        armor->unequip();
                }
           message_vision("$N�ӹ�$n���е�" + armor->name() + "�����߷첹�˼��롣\n", 
                                this_object(), me);
/*
                if (weapon->query("orig_name")) {
                        weapon->set("name", weapon->query("orig_name"));
                }
*/
                wname = replace_string( armor->name(), "�Ƶ���", "");
                armor->set("name", wname);
                message_vision("�����ˣ���$N�ݻ�" + wname + "��$n��\n",
                                this_object(), me);
                
                armor->add("armor_prop/armor", prop);
                armor->save();
        }
        return 1;
}
int do_ding(string arg)
{
        string ctype, cname, ccolor, cid, material;
        object ob, me, gold, ob2;
        string id,newfile,filename,timestamp;
        me = this_player();
        id = me->query("id");
        if(!arg || sscanf(arg,"%s %s %s %s %s",ctype,ccolor,cname,cid,material ) != 5)
        return notify_fail("ָ���ʽ��ding <type> <color> <name> <English name> <material>\n");
        if(me->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");
        /*if((int)me->query("created_item") >= (int)me->query("age")/10)
        return notify_fail("������ֻ��ӵ��"+chinese_number((int)me->query("age")/10)+
"��������Ʒ��\n");*/
        if((int)me->query("created_item") >= 5)
        return notify_fail("���Ѿ�ӵ��̫��������Ʒ�ˡ�\n");
        gold = present("gold_money", this_player());
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < 1)
        return notify_fail("������û���������ӡ�\n");
        if(!objectp(ob2=present(material,me)))
        return notify_fail("�����ϲ�û��"+material+"��\n");
        if(!(int)ob2->query("for_create_cloth"))
        return notify_fail(ob2->name()+"�����������������Ρ�\n");
        if( !check_legal_name(cname))
        return notify_fail("");
        if( !check_legal_id(cid))
        return notify_fail(""); 
        if( ccolor != "$BLK$" && 
            ccolor != "$NOR$" &&
            ccolor != "$RED$" &&
            ccolor != "$GRN$" &&
            ccolor != "$YEL$" &&
            ccolor != "$BLU$" &&
            ccolor != "$MAG$" &&
            ccolor != "$CYN$" &&
            ccolor != "$WHT$" &&
            ccolor != "$NOR$" &&
            ccolor != "$HIR$" &&
            ccolor != "$HIG$" &&
            ccolor != "$HIY$" &&
            ccolor != "$HIB$" &&
            ccolor != "$HIM$" &&
            ccolor != "$HIC$" &&
            ccolor != "$HIW$" 
        )
        return notify_fail("��֪��Ҫʲô��ɫ��\n");
        ccolor = replace_string(ccolor, "$BLK$", "BLK");
        ccolor = replace_string(ccolor, "$RED$", "RED");
        ccolor = replace_string(ccolor, "$GRN$", "GRN");
        ccolor = replace_string(ccolor, "$YEL$", "YEL");
        ccolor = replace_string(ccolor, "$BLU$", "BLU");
        ccolor = replace_string(ccolor, "$MAG$", "MAG");
        ccolor = replace_string(ccolor, "$CYN$", "CYN");
        ccolor = replace_string(ccolor, "$WHT$", "WHT");
        ccolor = replace_string(ccolor, "$HIR$", "HIR");
        ccolor = replace_string(ccolor, "$HIG$", "HIG");
        ccolor = replace_string(ccolor, "$HIY$", "HIY");
        ccolor = replace_string(ccolor, "$HIB$", "HIB");
        ccolor = replace_string(ccolor, "$HIM$", "HIM");
        ccolor = replace_string(ccolor, "$HIC$", "HIC");
        ccolor = replace_string(ccolor, "$HIW$", "HIW");
        ccolor = replace_string(ccolor, "$NOR$", "NOR");
        seteuid(ROOT_UID);
        switch( ctype ) {
                case "hat":
                        newfile = read_file("/obj/selfmake/armor/hat.o");
                        break;
                case "belt":
                        newfile = read_file("/obj/selfmake/armor/belt.o");
                        break;
                case "shoes":
                        newfile = read_file("/obj/selfmake/armor/shoes.o");
                        break;
                case "suit":
                        newfile = read_file("/obj/selfmake/armor/suit.o");
                        break;
                case "scarf":
                        newfile = read_file("/obj/selfmake/armor/scarf.o");
                        break;
           default:
                        return notify_fail("���ﲻ������Ҫ�Ķ�����\n");
        }
        timestamp = sprintf("%c%c%c%c%c%c%c",'a'+random(20),'a'+random(20),'a'+random(20),
        'a'+random(20),'a'+random(20),'a'+random(20),'a'+random(20));
        newfile = replace_string( newfile, "������", cname);
        newfile = replace_string( newfile, "order", cid);
        newfile = replace_string( newfile, "fengyun", id);
        newfile = replace_string( newfile, "COR", ccolor);
        newfile = replace_string( newfile, "STAMP", timestamp);
        filename = DATA_DIR+"login/" + id[0..0] + "/" + id + "/" + id +timestamp + ".c";
        if(!write_file(filename, newfile,1))
                return 0;
        ob = new(filename);
        if(ob2->query("equipped")) {ob2->unequip(); me->reset_action();}
        ob2->move(environment(me));
        ob->set("weight",ob2->query_weight());
        ob->set("armor_prop/armor",ob2->query("armor_prop/armor"));
        ob->set("max_enchant",ob2->query("max_enchant"));
        ob->set("base_armor",ob2->query("armor_prop/armor"));
        ob->save();
        ob->restore();
        if(ob->move(me)){
        gold->add_amount(-1);
        me->add("created_item",1);
        me->start_busy(1);
        write("�㽫���ϵ�"+ob2->name()+"����"+name()+"�������һ"+ob->query("unit")+
        ob->name()+"\n");
        destruct(ob2);
        seteuid(getuid());
        return 1;
        }
        return 0;
}
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 2) || (strlen(name) > 40 ) ) {
                write("�Բ����������ֱ�����һ����ʮ�������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ����������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ������ֱ��������ġ�\n");
                        return 0;
                }
        }
        return 1;
} 
int check_legal_id(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 3) || (strlen(name) > 20 ) ) {
                write("�Բ���Ӣ�����ֱ�����������ʮ�����֡�\n");
                return 0;
        } 
        return 1;
}     
