import { it, expect, describe } from "vitest";
import { threeSum } from "../three-sum";

describe("Three sum", () => {
  it("nums=[-1,0,1,2,-1,-4]  ----> [[-1,-1,2],[-1,0,1]]", () => {
    expect(threeSum([-1, 0, 1, 2, -1, -4])).toEqual([
      [-1, -1, 2],
      [-1, 0, 1],
    ]);
  });
  it("nums=[0,1,1]  ----> []", () => {
    expect(threeSum([0, 1, 1])).toEqual([]);
  });
  it("nums=[0,0,0]  ----> [[0,0,0]]", () => {
    expect(threeSum([0, 0, 0])).toEqual([[0, 0, 0]]);
  });
  it("nums=[-1,0,1,2,-1,-4,-2,-3,3,0,4]  ----> [[-4,0,4],[-4,1,3],[-3,-1,4],[-3,0,3],[-3,1,2],[-2,-1,3],[-2,0,2],[-1,-1,2],[-1,0,1]]", () => {
    expect(threeSum([-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4])).toEqual([
      [-4, 0, 4],
      [-4, 1, 3],
      [-3, -1, 4],
      [-3, 0, 3],
      [-3, 1, 2],
      [-2, -1, 3],
      [-2, 0, 2],
      [-1, -1, 2],
      [-1, 0, 1],
    ]);
  });
});
