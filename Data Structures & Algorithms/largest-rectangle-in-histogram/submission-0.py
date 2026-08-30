class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        stack = []  # Stores indices
        max_area = 0
        
        # Append 0 to flush remaining bars out of the stack at the end
        for i, h in enumerate(heights + [0]):
            while stack and heights[stack[-1]] > h:
                height_idx = stack.pop()
                height = heights[height_idx]
                
                # Calculate width based on the remaining element on stack
                width = i if not stack else i - stack[-1] - 1
                max_area = max(max_area, height * width)
                
            stack.append(i)
            
        return max_area