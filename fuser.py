import sys

def seperator(string, length):
    return [ ('0x' + string[i : i + length]) for i in range(0, len(string), length)]

def common(strings, length):
    perLine = 32 / length
    print('perLine: %d'.format(perLine))
    return '\n'.join(', '.join(strings[i : i + perLine]) for i in range(0, len(strings), perLine))

if __name__ == '__main__':
    url = sys.argv[1]
    length = int(sys.argv[2])

    perLine = 32 / length

    with open(url, 'r') as file:
        contents = file.read()

    contents = contents.replace(', ', '').replace('\n', '').replace('0x', '')

    with open(url, 'w') as file:
        file.write(contents)

    
