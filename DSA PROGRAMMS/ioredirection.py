import sys

def io_redirect(inputfile,outputfile,func):
    fin = open(inputfile,'r')
    fout = open(outputfile,'w')

    original_stdin = sys.stdin
    original_stdout = sys.stdout

    sys.stdin = fin
    sys.stdout = fout

    try:
        func()
    except Exception as e:
        print(f"Caught Exception => {e}")
    finally:
        sys.stdin = original_stdin
        sys.stdout = original_stdout
        fin.close()
        fout.close()

def o_redirect(outputfile,func):
    fout = open(outputfile,"w")

    original_stdout = sys.stdout

    sys.stdout = fout

    try:
        func()
    except Exception as e:
        print(f"Caught Exception as {e}")
    finally:
        sys.stdout = original_stdout
        fout.close()

def tinput(prompt=""): #terminal output
    sys.__stdout__.write(prompt)
    sys.__stdout__.flush()
    # return input()
    return sys.__stdin__.readline().strip()