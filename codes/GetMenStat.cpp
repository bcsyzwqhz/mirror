#include<bits/stdc++.h>
#include<unistd.h>
#define endl '\n'
using namespace std;
typedef struct MEMINFO
{
	unsigned long memtotal,
				memfree,
				memavailable;
	char name1[20],name2[20],name3[20];			
}MEM_INFO;
bool GetMemInfo(MEM_INFO *lp)
{
	FILE *fd;
	char buff[128];
	fd=fopen("/proc/meminfo","r");
	if(fd<0) return 0;
	fgets(buff,sizeof(buff),fd);
	sscanf(buff,"%s %lu ",lp->name1,&lp->memtotal);
	fgets(buff,sizeof(buff),fd);
	sscanf(buff,"%s %lu ",lp->name2,&lp->memfree);
	fgets(buff,sizeof(buff),fd);
	sscanf(buff,"%s %lu ",lp->name3,&lp->memavailable);
	fclose(fd);
	return 1;
 } 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	MEN_INFO m;
	GetMemInfo(&m);
	cout<<m.name1<<" "<<m.memtotal<<endl;
	cout<<m.name2<<" "<<m.memfree<<endl;
	cout<<m.name3<<" "<<m.memavailable<<endl;
    return 0;
}

