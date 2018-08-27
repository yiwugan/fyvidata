#define NETBAR_SITES "/adm/etc/netbar_sites"
#define NETBARN_SITES "/adm/etc/netbarn_sites"
void load_sites();
void add(string pattern);
void delete(string pattern);
int  is_netbar(string site);
void print(); 
string *Sites;
string *OKSites;
void create()
{
        seteuid(getuid());
        load_sites();
} 
void load_sites()
{
        string *tmp, file;
        int loop; 
        Sites = ({});
        OKSites = ({}); 
        // reads in the list of the netbar sites 
        file = read_file(NETBAR_SITES);
        if (!file) return;
        
        tmp = explode(file, "\n");
        for(loop=0; loop<sizeof(tmp); loop++)
                if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                        continue;
                else Sites += ({ tmp[loop] }); 
        // reads in the list of the not netbar sites
        file = read_file(NETBARN_SITES);
        if (!file) return; 
        tmp = explode(file, "\n");
        for(loop=0; loop<sizeof(tmp); loop++)
                if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                        continue;
                else OKSites += ({ tmp[loop] });
        return;
} 
int is_netbar(string site)
{
        string *line;
        int i; 
        line = ({});
        line += ({site});
        for (i = 0; i < sizeof(OKSites); i++)
                if (sizeof(regexp(line, OKSites[i])) == 1)
                        return 0; 
        for (i = 0; i < sizeof(Sites); i++)
                if (sizeof(regexp(line, Sites[i])) == 1)
                {
                        return 1;
                }
        return 0;
}        
void print()
{
        int i;
        write("NETBAR:\n");
        for (i = 0; i < sizeof(Sites); i++)
                write(Sites[i] + "\n");
        write("NETBARN:\n");
        for (i = 0; i < sizeof(OKSites); i++)
                write(OKSites[i] + "\n");
} 
void add(string site)
{
        int i;
        
        Sites += ({site});
        write_file(NETBAR_SITES, Sites[sizeof(Sites)-1] + "\n", 0);
        write("�ϣ��ˣ�\n"); 
} 
void delete(string site)
{
        int i; 
        OKSites += ({site});
        write_file(NETBARN_SITES, OKSites[sizeof(OKSites)-1] + "\n", 0);
        write("�ϣ��ˣ�\n");
//      ��������ֶ��޸�netbar_sites,������bug������ȫ����� 
} 
void dynamic_add(string site)
{
        Sites += ({site}); 
} 
void dynamic_remove(string site)
{
        OKSites += ({site}); 
}     
