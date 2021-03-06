 // hockshop.c
inherit ROOM;
#define MAX_PAWN 50
void init()
{
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw"); 
} 
string value_string(int value)
{
        if( value < 1 ) value = 1;
        else if( value < 100 )
                return chinese_number(value) + "文钱";
        else
                return chinese_number(value/100) + "两"
                        + (value%100? "又" + chinese_number(value%100) + "文钱": "");
} 
void pay_player(object who, int amount) 
{
        object ob; 
        if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
        if( amount/10000 ) {
           ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
} 
int do_value(string arg)
{
        object ob;
        int value; 
        if( !arg || !(ob = present(arg, this_player())) )
                return notify_fail("你要拿什麽物品给当铺估价？\n"); 
        if( ob->query("money_id") )
                return notify_fail("这是「钱」，你没见过吗？\n"); 
        value = ob->query("value");
        if( !value ) printf("%s一文不值。\n", ob->query("name"));
        else 
                printf("%s价值%s。\n如果你要典当(pawn)，可以拿到%s。\n如果卖断(sell)，可以拿到%s。\n",
                        ob->query("name"), value_string(value),
                        value_string(value * 25 / 100), value_string(value * 80 / 100)); 
        return 1;
} 
int do_pawn(string arg)
{
        object ob;
        string term, *terms;
        string data;
        int value,  pawn_count, i;
        int rvalue;
   mapping pawn;
        object me;
        me = this_player();
        pawn = me->query("pawn");
        if( !arg || !(ob = present(arg, this_player())) )
        {
        write("你目前典当的物品有：\n");
        if( !mapp(pawn) ||   !sizeof(pawn) )
                write("\t没有任何典当的物品。\n");
        else {
                        terms = keys(pawn);
                        for(i=0; i<sizeof(terms); i++)
                                printf("%-5s：  %-15s  赎银：%O\n", terms[i], pawn[terms[i]],
                        value_string(((int)me->query("vpawn/"+terms[i]))* 3/4));
              }
        return 1;
        }
        if( ob->query("money_id") )     return notify_fail("你要当「钱」？\n"); 
        value = ob->query("value");
        if( !(value/4) ) return notify_fail("这样东西并不值很多钱。\n");
        if( mapp(pawn) && sizeof(pawn))
                {
                        terms = keys(pawn);
                        if(sizeof(terms) > MAX_PAWN)
                        return notify_fail("你已典当太多物品了。\n");
                        for(i=0; i<sizeof(terms); i++)
                        {
                        pawn_count = i;
                        if(!((int) me->query("vpawn/" + sprintf("%d", i))))
                         break;
                        else pawn_count = i+1;
                        }
                }
        else pawn_count = 0;
        term = ob->query("name");
        data = base_name(ob)+ ".c";
        me->set("pawn/"+ sprintf("%d",pawn_count),  term);
        me->set("vpawn/"+sprintf("%d",pawn_count), ob->query("value"));
        me->set("fpawn/"+sprintf("%d",pawn_count), data);
        me->save();
   message_vision("$N把身上的" + ob->query("name") + "拿出来典当了"
                + value_string(value * 25 / 100) + "。\n", this_player()); 
        pay_player(this_player(), value * 25 / 100 );
        destruct(ob); 
        return 1;
} 
int do_sell(string arg)
{
        object ob;
        int value; 
        if( !arg || !(ob = present(arg, this_player())) )
                return notify_fail("你要卖断什麽物品？\n"); 
        if( ob->query("money_id") )     return notify_fail("你要卖「钱」？\n");
        value = ob->query("value");
        if( !value ) return notify_fail("这样东西不值钱。\n");  
        message_vision("$N把身上的" + ob->query("name") + "卖掉。\n",
                this_player()); 
        pay_player(this_player(), value  * 80 / 100);
        destruct(ob); 
        return 1;
}
void pay_him(object who, int amount) 
{
        object ob;
        object cash, tencash, gold, silver, coin;
        tencash = present("tenthousand-cash_money", who);
        cash = present("thousand-cash_money", who);
        gold = present("gold_money",who);
        silver = present("silver_money",who);
        coin = present("coin_money",who);
        if(tencash) destruct(tencash);
        if(cash) destruct(cash);
        if(gold) destruct(gold);
        if(silver) destruct(silver);
        if(coin) destruct(coin);  
        if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
} 
int affordable(object me, int amount)
{
        int total;
        object cash, tencash, gold, silver, coin; 
        tencash = present("tenthousand-cash_money", me);
        cash = present("thousand-cash_money", me);
        gold = present("gold_money",me);
        silver = present("silver_money",me);
        coin = present("coin_money",me); 
        total = 0;
        if( tencash) total += tencash->value();
        if( cash) total += cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value(); 
        if( total < amount ) return 0; 
        return total;
}
int do_redeem(string arg)
{
        int num;
        int amount;
        string ob_file;
        object ob;
        object me;
        int afford;
        if( !arg || sscanf(arg, "%d", num)!=1 )
                return notify_fail("指令格式：redeem <物品标号>\n");
        me = this_player();
        amount = (int) me->query("vpawn/" + sprintf("%d", num));
        if( !amount )
                return notify_fail("有这个物品标号吗？\n");
        amount = amount * 3 /4;
        if( afford = affordable(me, amount) ) {
                pay_him(me, afford-amount);
                ob_file = me->query("fpawn/"+sprintf("%d",num));
                ob = new(ob_file);
                ob->move(me);
                me->delete("pawn/"+sprintf("%d",num));
                me->delete("vpawn/"+sprintf("%d",num));
                me->delete("fpawn/"+sprintf("%d",num));
                me->save();
                message_vision("$N赎回了$n。\n", me, ob);
                return 1;
        } else
                return notify_fail("你的钱不够。\n"); 
}
int do_convert(string arg)
{
        string from, to;
        int amount, bv1, bv2;
        object from_ob, to_ob;
        if( this_player()->is_busy() )
                return notify_fail("你的动作还没有完成，不能兑换钱。\n");
   if( !arg || sscanf(arg, "%d %s to %s", amount, from, to)!=3 )
                return notify_fail("指令格式：convert <数量> <货币种类> to <货币种类>\n"); 
        from_ob = present(from + "_money", this_player());
        to_ob = present(to + "_money", this_player());
        if( !to_ob && file_size("/obj/money/" + to + ".c") < 0 )
                return notify_fail("你想兑换哪一种钱？\n"); 
        if( !from_ob )          return notify_fail("你身上没有这种货币。\n");
        if( amount < 1 )        return notify_fail("兑换货币一次至少要兑换一个。\n");
                
        if( (int)from_ob->query_amount() < amount )
                return notify_fail("你身上没有那麽多" + from_ob->query("name") + "。\n"); 
        bv1 = from_ob->query("base_value");
        if( !bv1 ) return notify_fail("这种东西不值钱。\n"); 
        bv2 = to_ob ? to_ob->query("base_value") : call_other("/obj/money/" + to, "query", "base_value" ); 
        if( bv1 < bv2 ) amount -= amount % (bv2 / bv1);
        if( amount==0 ) return notify_fail("这些" + from_ob->query("name") + "的价值太低了，换不起。\n");
        from_ob->add_amount(-amount);
        if( !to_ob ) {
                to_ob = new("/obj/money/" + to);
                to_ob->move(this_player());
                to_ob->set_amount(amount * bv1 / bv2);
        } else
                to_ob->add_amount(amount * bv1 / bv2); 
        message_vision( sprintf("$N从身上取出%s%s%s，换成%s%s%s。\n",
                chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
                chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), to_ob->query("name")),
                this_player() ); 
        this_player()->start_busy(1);
        return 1;
}  
int do_deposit(string arg)
{
        int bv,amount;
        int damount;
        string type;
        object type_ob;
       if( this_player()->is_busy() )
                return notify_fail("你的动作还没有完成，不能存钱。\n");
        if( !arg || sscanf(arg, "%d %s", amount, type)!=2 )
                return notify_fail("指令格式：deposit <数量> <货币种类>\n");
        if( amount <= 0)
                return notify_fail("指令格式：deposit <数量> <货币种类>\n");
        type_ob = present(type + "_money", this_player());
        if( !type_ob)          return notify_fail("你身上没有这种货币。\n");
        if( (int)type_ob->query_amount() < amount )
                return notify_fail("你身上没有那麽多" + type_ob->query("name") + "。\n");
        bv = type_ob->query("base_value");
        if( !bv ) return notify_fail("这种东西不值钱。\n");
        damount = (int) this_player()->query("deposit");
        damount += amount * bv;
        this_player()->set("deposit", damount);
        type_ob->add_amount(-amount);
        message_vision(sprintf("$N存入了%s%s%s。\n",
        chinese_number(amount), type_ob->query("base_unit"), type_ob->query("name")), this_player());
        this_player()->start_busy(1);
        return 1; 
}
int do_balance(string arg)
{
        int value;
        value= (int) this_player()->query("deposit");
        tell_object(this_player(),"你现在共有存款：\n");
        if( value < 100 )
                {
                tell_object(this_player(),chinese_number(value)+"文钱．\n");
                return 1;
                }
        else
                        {
                tell_object(this_player(), chinese_number(value/100) + "两"
        + (value%100? "又" + chinese_number(value%100) + "文钱．": "") + "\n");
                        return 1;
                        }
} 
int do_withdraw(string arg)
{
        int amount;
        int hamount;
        if( !arg || sscanf(arg, "%d", amount)!=1 )
                return notify_fail("指令格式：withdraw <数量> \n");
        if(amount <=0 )
                return notify_fail("指令格式：withdraw <数量> \n");
        hamount = (int) this_player()->query("deposit");
        if(amount>hamount) 
                return notify_fail("你没这么多存款 ！！\n");
        hamount -=amount;
        this_player()->set("deposit", hamount);
        pay_player(this_player(), amount);
        tell_object(this_player(), "ＯＫ \n");
        return 1; 
}      
