import file_reader as R
import display_manager as D


if __name__=='__main__':
    loc=input("Enter Location of social_network.txt:")
    if len(loc)==0:
        loc='social_network.txt'
    elif loc[-1]=='/':
        loc+='social_network.txt'
    else :
        loc+='/social_network.txt'

    reader=R.file_reader(loc)
    reader.read()
    #data = {
    #    "users",tuple(reader.members),
    #    "groups",tuple(reader.groups)
    #}
    manager = D.manager(reader.members,reader.groups)
    manager.run()
