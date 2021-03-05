from group import *
from user import *

class file_reader:
    def __init__(self,loc):
        self.loc=loc
        self.file=open(self.loc,"r")
        self.members=[]
        self.groups=[]

    def read(self):
        members=False
        groups=False
        for x in self.file:
            temp=x.upper()
            if "#" in temp:
                if "USERS" in temp:
                    members=True
                    groups=False
                if "GROUPS" in temp:
                    members=False
                    groups=True
            if members:
                if x[0]=='<':
                    index=x.find(':')
                    member=user(x[1:index])
                    while index != -1:
                        index_temp=x.find(',',index+1)
                        member.update_contacts(x[index+1:index_temp])
                        index=index_temp
                    self.members.append(member)
            if groups:
                if x[0]=='<':
                    index=x.find(':')
                    grp=group(x[1:index])
                    while index != -1:
                        index_temp=x.find(',',index+1)
                        grp.update_members(x[index+1:index_temp])
                        index=index_temp
                    self.groups.append(grp)
                    for m in grp.members:
                        for n in self.members:
                            if n.id == m:
                                n.update_group(grp)
                                #print("heree")



    

