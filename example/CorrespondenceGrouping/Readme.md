
After you have created the executable, you can then launch it following this example:

```bash
> correspondence_grouping milk.pcd milk_cartoon_all_small_clorox.pcd
Or, alternatively, if you prefer specifying the radii in units of cloud resolution:
```

```bash
> correspondence_grouping milk.pcd milk_cartoon_all_small_clorox.pcd -r --model_ss 7.5 --scene_ss 20 --rf_rad 10 --descr_rad 15 --cg_size 10
```


code from
https://pcl.readthedocs.io/projects/tutorials/en/master/correspondence_grouping.html

