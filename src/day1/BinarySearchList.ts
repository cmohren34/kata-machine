export default function bs_list(haystack: number[], needle: number): boolean {
    let low = 0;
    let high = haystack.length;

    do {
        const mid = Math.floor(low + (high - low) / 2);
        const curr = haystack[mid];

        if (curr == needle) {
            return true;
        } else if (curr < needle) {
            low = mid + 1;
        } else {
            high = mid;
        }
    } while (low < high);

    return false;
}
