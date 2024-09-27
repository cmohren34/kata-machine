export default function two_crystal_balls(breaks: boolean[]): number {
    const jmpAmount = Math.floor(Math.sqrt(breaks.length));

    let i = jmpAmount;
    for (; i < breaks.length; i += jmpAmount) {
        if (breaks[i]) {
            break;
        }
    }

    // jump back since we have discovered a break
    i -= jmpAmount;

    // now we linear search from the last know unbreakable position to
    // j makes sure we only increment max sqrt(n) times, i starts from the last good pos. and iterates until it either breaks or we hit the end
    for (let j = 0; j < jmpAmount && i < breaks.length; ++j, ++i) {
        if (breaks[i]) {
            return i;
        }
    }

    return -1;
}
