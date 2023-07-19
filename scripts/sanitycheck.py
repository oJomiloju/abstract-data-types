import subprocess
import sys
from benedict import benedict

path = 'tests/tests.yml'

sys.tracebacklimit = 0
COLORIZED = True
if COLORIZED:
    ENDCODE = '\033[0m'
    BOLD = '\033[1m'
    GREEN = '\033[92m'
    RED = '\033[91m'
else:
    ENDCODE = ''
    BOLD = ''
    GREEN = ''
    RED = ''

def test_output(cmd, correct_output):
    with subprocess.Popen(
            cmd, stdout=subprocess.PIPE) as p:
        output = p.stdout.read()
        returncode = p.poll()
        p.kill()
    return output, returncode


def test(name, tests, test_type="output", points=1):
    print('\n', BOLD, name, ENDCODE)
    print(" ", '-'*20)
    correct = 0
    for correct_output, cmd, testname in tests:
        print("  " + testname)
        print("  TEST:", cmd[1:])
        output, returncode = test_output(cmd, correct_output)
        # output = output.decode("utf-8")
           
        try:
            if test_type == "output":
                correct_output = correct_output.encode('ascii')       
                assert output == correct_output
            else:
                output = returncode
                assert returncode == correct_output
            correct += 1
            print(GREEN, "   PASS", '✓', ENDCODE)
            print(f'    YOURS: {output}\n    OURS : {correct_output}')
        except Exception as err:
            print(RED, "   FAIL", '✗', ENDCODE)
            print(f'    YOURS: {output}\n    OURS : {correct_output}')

    return correct, len(tests), points, name


currentResult = None  # holds last result object passed to run method


if __name__ == '__main__':
    d = benedict.from_yaml(path)
    
    PROBLEM_NAME = d['problem']

    results = []

    for suite in d["suites"]:
        tests = [(t["solution"], t["command"], t["name"]) for t in suite["tests"]]
        results.append(test(suite["name"], tests, suite["type"], suite["pts"]))
        print("\n", '*'*20)

    

    print(f" {BOLD}{PROBLEM_NAME}{ENDCODE}")
    print("", '*'*20)
    print('\n', BOLD, "SUMMARY", ENDCODE)
    print(" ", '-'*20)
    sumpts = 0
    sumpts_correct = 0 
    for t in results:
        correct, total, pts, name = t
        pts = pts + 0.000
        grade = correct/total*pts
        print(" ", name)
        print(f"    {grade}/{pts} pts")
        sumpts_correct = sumpts_correct + grade
        sumpts = sumpts + pts
    print("\n", '*'*20)
    print(f"{BOLD} FINAL GRADE: {sumpts_correct} / {sumpts} pts: {sumpts_correct/sumpts*100}%{ENDCODE}")
    print("", '*'*20)
    print(sumpts_correct)

