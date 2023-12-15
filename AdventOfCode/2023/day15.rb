
def elf_hash(word)
    curr = 0
    for asc in word.each_byte.to_a
        curr += asc
        curr = (curr * 17) % 256
    end
    return curr
end

def part1(puzzle)
    answer = 0
    for word in puzzle
        answer += elf_hash(word)
    end
    print(answer)
end

class Pair
    include Comparable
    attr :first
    attr :second
    def <=> (other)
        first <=> other.first
    end
    def initialize(first, second)
        @first = first
        @second = second
    end
    def inspect
        return "#{@first} #{@second}"
    end
end

def part2(puzzle)
    printer = Hash.new
    for box in 0..255
        printer[box] = []
    end
    for data in puzzle
        exploder = data.index('=') == nil ? '-' : '='
        states = data.split(exploder)
        lens = states[0]
        box_number = elf_hash(lens)
        focal = states[1]
        lens_with_focal = Pair.new(lens, focal)
        if (exploder == '-')
            remove = printer[box_number].index(lens_with_focal)
            if (remove != nil)
                printer[box_number].delete_at(remove)
            end
        else
            update = printer[box_number].index(lens_with_focal)
            if (update == nil)
                printer[box_number].push(lens_with_focal)
            else
                printer[box_number][update] = lens_with_focal
            end
        end
    end
    answer = 0
    for box in 0..255
        printer[box].each_with_index do |local_lens, idx|
            answer += (box + 1) * (idx + 1) * (local_lens.second.to_i)
        end
        # print(box , printer[box] , "\n")
    end
    print(answer)
end
input = File.read("../../io/input.in")
toSolve = input.chomp.split(',')

# part1(toSolve)
part2(toSolve)
