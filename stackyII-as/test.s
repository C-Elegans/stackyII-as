call test
jump end
test:
frame 1
push 0
slocal 1
local 1
push 1
add
slocal 1
local 1
out
leave
ret
end: